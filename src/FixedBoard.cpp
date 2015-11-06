#include "FixedBoard.hpp"

/**
* @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*/

/**
* Create a simple empty board.
*
* @param const size_t width
* @param const size_t height
*/
FixedBoard::FixedBoard(const size_t width, const size_t height)
 : tiles_(new gsl::owner<TileInterface*> [width*height]),
   linearizer_(new HorizontalLinearizer2D(width, height))
{ }

/**
* Create a simple empty board with a specific storing way.
*
* @param const size_t width
* @param const size_t height
* @param gsl::owner<Linearizer2D*> linearizer
*/
FixedBoard::FixedBoard(
  const size_t width,
  const size_t height,
  gsl::owner<Linearizer2D*> linearizer
) : tiles_(new gsl::owner<TileInterface*> [width*height]),
    linearizer_(linearizer)
{
  linearizer_->setHeight(height);
  linearizer_->setWidth(width);
}

/**
* Copy an existing board (deep-copy).
*
* @param const BoardInterface& toCopy
*/
FixedBoard::FixedBoard(const Board& toCopy)
: linearizer_(
    new HorizontalLinearizer2D(toCopy.getWidth(), toCopy.getHeight())
  ),
  tiles_ = (new TileInterface*[toCopy.getWidth()*toCopy.getHeight()])
{
  for(
    auto tileIterator = toCopy.begin();
    tileIterator != toCopy.end();
    ++tileIterator
  ) {
    if(*tileIterator != nullptr) {
      setTile(
        tileIterator.getX(),
        tileIterator.getY(),
        (*tileIterator)->copy()
      );
    }
  }
}

/**
* Board destructor, the board will destroy its tiles.
*/
FixedBoard::~FixedBoard()
{
  for(
    auto tileIterator = begin();
    tileIterator != end();
    ++tileIterator
  ) {
    if((*tileIterator) != nullptr) {
      delete *boardIterator;
	    *boardIterator = nullptr;
    }
  }

  delete tiles_;
  tiles_ = nullptr;
  delete linearizer_;
  linearizer_ = nullptr;
}

/**
* Return the board height
*
* @return std::size_t
*/
std::size_t FixedBoard::getHeight() const
{
  return linearizer_->getHeight();
}

/**
* Return the board width.
*
* @return std::size_t
*/
std::size_t FixedBoard::getWidth() const
{
  return linearizer_->getWidth();
}

/**
* Return a begin iterator over this board.
*
* @return BoardIterator
*/
BoardIterator FixedBoard::begin()
{
  return BoardIterator(this);
}

ConstBoardIterator FixedBoard::begin() const
{
  return ConstBoardIterator(this);
}

/**
* Return an end iterator over this board.
*
* @return BoardIterator
*/
BoardIterator FixedBoard::end()
{
  return BoardIterator(this, linearizer_->getMaxLinearizedValue());
}

ConstBoardIterator FixedBoard::end() const
{
  return ConstBoardIterator(this, linearizer_->getMaxLinearizedValue());
}

/**
* Return a tile at a specific location.
*
* @param const std::size_t x
* @param const std::size_t y
*
* @throws std::out_of_range If the location (x,y) do not exist.
*
* @return TileInterface* Tile at the (x,y) location, while return nullptr
*                        if the tile do not exist.
*/
TileInterface* FixedBoard::getTile(
  const std::size_t x,
  const std::size_t y
)
{
  return tiles_[linearizer_->linearize(x,y)];
}

const TileInterface* FixedBoard::getTile(
  const std::size_t x,
  const std::size_t y
) const
{
  return tiles_[linearizer_->linearize(x,y)];
}

/**
* Set a tile in a specific location.
*
* If a tile already exist at the location, this object will destroy it.
*
* @param const std::size_t x
* @param const std::size_t y
* @param gsl::owner<TileInterface*> tile Tile to set.
*
* @throws std::out_of_range If the location (x,y) do not exist.
*
* @return void
*/
void FixedBoard::setTile(
  const std::size_t x,
  const std::size_t y,
  gsl::owner<TileInterface*> tile
)
{
  const std::size_t location = linearizer_->linearize(x,y);

  gsl::owner<TileInterface*> oldTile = tiles_[location];
  tiles[location] = tile;

  if(oldTile != nullptr) {
    delete oldTile;
    oldTile = nullptr;
  }
}

/**
* Check if a location is in the board.
*
* @param const std::size_t x
* @param const std::size_t y
*
* @return bool True if the (x,y) location is in the board.
*/
bool FixedBoard::contains(const std::size_t x, const std::size_t y) const
{
  return linearizer_->contains(x,y);
}
