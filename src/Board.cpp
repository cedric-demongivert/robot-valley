#include "Board.hpp"

/**
* @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*/

/**
* Create a simple empty board.
*
* @param const size_t width
* @param const size_t height
*/
Board::Board(const size_t width, const size_t height)
{
  width_ = width;
  height_ = height;
  tiles_ = new TileInterface*[width_*height_];
}

/**
* Copy an existing board (deep-copy).
*
* @param const BoardInterface& toCopy
*/
Board::Board(const BoardInterface& toCopy)
{
  width_ = toCopy.width_;
  height_ = toCopy.height_;
  tiles_ = new TileInterface*[width_*height_];

  for(size_t x = 0; x < width_; ++x) {
    for(size_t y = 0; y < height_; ++y) {
      tiles_[x * width_ + y] = toCopy.getTile(x,y).copy();
    }
  }
}

/**
* Board destructor, the board will destroy its tiles.
*/
Board::~Board()
{
  for(auto boardIterator = begin(); boardIterator != end(); boardIterator ++) {
    if((*boardIterator) != nullptr) {
      delete *boardIterator;
	    *boardIterator = nullptr;
    }
  }

  delete tiles_;
}

/**
* Return the board height.
*
* @return size_t
*/
std::size_t Board::getHeight() const
{
  return height_;
}

/**
* Return the board width.
*
* @return size_t
*/
std::size_t Board::getWidth() const
{
  return width_;
}

/**
* Return a begin iterator over this board.
*
* @return BoardIterator
*/
BoardIterator Board::begin()
{
  return BoardIterator(this);
}

ConstBoardIterator Board::begin() const
{
  return ConstBoardIterator(this);
}

/**
* Return an end iterator over this board.
*
* @return BoardIterator
*/
BoardIterator Board::end()
{
  return BoardIterator(this, width_*height_ + 1);
}

ConstBoardIterator Board::end() const
{
  return ConstBoardIterator(this, width_*height_ + 1);
}

/**
* Return a tile at a specific location.
*
* @param const std::size_t x
* @param const std::size_t y
*
* @throws BoardOutOfBoundsException If the location (x,y) do not exist.
*
* @return TileInterface* Tile at the (x,y) location, while return nullptr if
*                        the tile do not exist.
*/
TileInterface* Board::getTile(
  const std::size_t x,
  const std::size_t y
)
{
  return tiles_[x*width_ + y];
}

const TileInterface* Board::getTile(
  const std::size_t x,
  const std::size_t y
) const
{
  return tiles_[x*width_ + y];
}

/**
* Set a tile in a specific location.
*
* If a tile already exist at the location, this object will destroy it.
*
* @param const std::size_t x
* @param const std::size_t y
* @param TileInterface* tile Tile to set.
*
* @throws BoardOutOfBoundsException If the location (x,y) do not exist.
*
* @return void
*/
void Board::setTile(
  const std::size_t x,
  const std::size_t y,
  TileInterface* tile
)
{
  TileInterface* oldTile = tiles_[x*width_ + y];
  tiles[x*width_ + y] = tile;

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
bool Board::isIn(const std::size_t x, const std::size_t y) const
{
  return x >= 0 && y >= 0 && x < width_ && y < height_;
}
