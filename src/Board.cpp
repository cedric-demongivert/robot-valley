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
* Create a simple empty board.
*
* @param const BoardInterface& toCopy
*/
Board::Board(const BoardInterface& toCopy)
{
  width_ = toCopy.width_;
  height_ = toCopy.height_;
  tiles_ = new TileInterface*[width_*height_];
}

virtual ~Board()
{

}
