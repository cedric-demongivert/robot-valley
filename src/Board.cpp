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

std::size_t Board::getHeight() const 
{
  return height_;
}

std::size_t Board::getWidth() const 
{
  return width_;
}

TileInterface* Board::getTile(const int x, const int y)
{
  return tiles_[x*width_ + y];
}

const TileInterface* Board::getTile(const int x, const int y) const
{
  return tiles_[x*width_ + y];
}

void Board::setTile(const int x, const int y, TileInterface* tile) 
{
  TileInterface* oldTile = tiles_[x*width_ + y];
  tiles[x*width_ + y] = tile;

  if(oldTile != nullptr) {
    delete oldTile;
    oldTile = nullptr;
  }
}

bool Board::isIn(const int x, const int y) const
{
  return x >= 0 && y >= 0 && x < width_ && y < height_;
}












