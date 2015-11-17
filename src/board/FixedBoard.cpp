#include "board/FixedBoard.hpp"

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
   linearizer_(new HorizontalLinearizer2D(width, height)),
   game_(nullptr)
{ }

/**
* Create a simple empty board with location.
*
* @param const size_t width
* @param const size_t height
* @param const int x
* @param const int y
*/
FixedBoard::FixedBoard(const size_t width, const size_t height, const int x, const int y)
  : tiles_(new gsl::owner<TileInterface*>[width*height]),
    linearizer_(new HorizontalLinearizer2D(width, height, x, y)),
    game_(nullptr)
{}

/**
* Create a simple empty board with a specific storing way and a location.
*
* @param const size_t width
* @param const size_t height
* @param const int x
* @param const int y
* @param gsl::owner<Linearizer2D*> linearizer
*/
FixedBoard::FixedBoard(
  const size_t width,
  const size_t height,
  const int x,
  const int y,
  gsl::owner<Linearizer2D*> linearizer
) : tiles_(new gsl::owner<TileInterface*>[width*height]),
    linearizer_(linearizer),
    game_(nullptr)
{
  linearizer_->setHeight(height);
  linearizer_->setWidth(width);
  linearizer_->setOffsetX(x);
  linearizer_->setOffsetY(y);
}

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
    linearizer_(linearizer),
    game_(nullptr)
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
  : linearizer_(new HorizontalLinearizer2D(toCopy.getWidth(), toCopy.getHeight())),
    tiles_(new TileInterface*[toCopy.getWidth()*toCopy.getHeight()]),
    game_(nullptr)
{
  for(const TileInterface* tile : toCopy) {
    if(tile != nullptr) {
      tile->copy(this);
    }
  }
}

/**
 * Board destructor, the board will destroy its tiles.
 */
FixedBoard::~FixedBoard()
{
  for (TileInterface* tile : *this) {
    if(tile != nullptr) {
      delete tile;
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
* Return the x coordinate of the first tile in that board.
*
* @return int
*/
int FixedBoard::getX() const
{
  return linearizer_->getOffsetX();
}

/**
* Return the y coordinate of the first tile in that board.
*
* @return int
*/
int FixedBoard::getY() const
{
  return linearizer_->getOffsetY();
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

/**
 * Return a begin iterator over this board.
 *
 * @return ConstBoardIterator
 */
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

/**
 * Return an end iterator over this board.
 *
 * @return ConstBoardIterator
 */
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
  const int x,
  const int y
)
{
  return tiles_[linearizer_->linearize(x,y)];
}

/**
* Return a tile at a specific location.
*
* @param const int x
* @param const int y
*
* @throws std::out_of_range If the location (x,y) do not exist.
*
* @return const TileInterface* Tile at the (x,y) location, while return nullptr if
*                        the tile do not exist.
*/
const TileInterface* FixedBoard::getTile(
  const int x,
  const int y
) const
{
  return tiles_[linearizer_->linearize(x,y)];
}

/**
* Set a tile in a specific location.
*
* If a tile already exist at the location, this object will destroy it.
*
* @param const int x
* @param const int y
* @param gsl::owner<TileInterface*> tile Tile to set.
*
* @throws std::out_of_range If the location (x,y) do not exist.
*
* @return void
*/
void FixedBoard::setTile(
  const int x,
  const int y,
  gsl::owner<TileInterface*> tile
)
{
  const std::size_t location = linearizer_->linearize(x,y);

  gsl::owner<TileInterface*> oldTile = tiles_[location];
  tiles_[location] = tile;

  if(oldTile != nullptr) {
    delete oldTile;
    oldTile = nullptr;
  }
}

/**
* Copy a tile in a specific location.
*
* If a tile already exist at the location, the board will destroy it.
*
* @param const int x
* @param const int y
* @param const TileInterface& tile Tile to set.
*
* @throws std::out_of_range If the location (x,y) do not exist.
*
* @return void
*/
void FixedBoard::setTile(
  const int x,
  const int y,
  const TileInterface& tile
)
{
  tile.copy(this, x, y);
}

/**
* Check if a location is in the board.
*
* @param const int x
* @param const int y
*
* @return bool True if the (x,y) location is in the board.
*/
bool FixedBoard::contains(const int x, const int y) const
{
  return linearizer_->contains(x,y);
}

/**
* Pass a turn.
*/
void FixedBoard::nextTurn()
{
  for (TileInterface* tile : *this) {
    if (tile != nullptr) {
      tile->nextTurn();
    }
  }
}

/**
 * Return the Game that use that board.
 * 
 * @return Game* game
 */
Game* FixedBoard::getGame()
{
  return game_;
}

/**
 * Return the Game that use that board.
 * 
 * @return const Game* game
 */
const Game* FixedBoard::getGame() const
{
  return game_;
}

/**
 * Change the Game that use that board.
 * 
 * @return Game* game
 */
void FixedBoard::setGame(Game* game)
{
  if(game != game_) {
    
    if(game_ != nullptr) {
      Game* oldGame = game_;
      game_ = nullptr;
      oldGame->setBoard(nullptr);
    }
    
    game_ = game;
    
    if(game_ != nullptr) {
     gsl::owner<Board*> oldBoard = game_->setBoard(this);
     if(oldBoard != nullptr) delete oldBoard; 
    }
    
  }
}
