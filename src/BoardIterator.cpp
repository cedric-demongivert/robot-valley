#include "BoardIterator.hpp"

/**
* Create a new BoardIterator at the begining of a board.
*
* @param BoardInterface* board Board to iterate.
*/
BoardIterator::BoardIterator(BoardInterface* board)
{
  board_ = board;
  i_ = linearize(0, 0);
}

/**
* Create a new BoardIterator at a specific location of a board.
*
* @param BoardInterface* board Board to iterate.
* @param const int x
* @param const int y
*/
BoardIterator::BoardIterator(BoardInterface* board, const int x, const int y)
{
  board_ = board;
  i_ = linearize(x, y);
}

/**
* Create a new BoardIterator at a specific linearized location of a board.
*
* @param BoardInterface* board Board to iterate.
* @param const int i
*/
BoardIterator::BoardIterator(BoardInterface* board, const int i)
{
  board_ = board;
  i_ = i;
}

/**
* Create a new copy of another BoardIterator.
*
* @param BoardIteratorInterface& toCopy Iterator to copy.
*/
BoardIterator::BoardIterator(const BoardIteratorInterface& toCopy)
{
  board_ = toCopy.board_;
  i_ = toCopy.i_
}

/**
* Destructor
*/
BoardIterator::~BoardIterator()
{ }

/**
* Get actual iterator x location.
*
* @return int
*/
int BoardIterator::getX() const
{
  return (int)(i / board->getWidth());
}

/**
* Get actual iterator y location.
*
* @return int
*/
int BoardIterator::getY() const
{
  return i_ % board_->getWidth();
}

/**
* Return the itered board.
*
* @return BoardIteratorInterface*
*/
BoardIteratorInterface* BoardIterator::getBoard() const
{
  return board_
}

/**
* Linearize a 2D location.
*/
int BoardIterator::linearize(const int x, const int y) const
{
  return x * board_->getWidth() + y;
}

/**
* Create a new BoardIterator at the begining of a board.
*
* @param const BoardInterface* board Board to iterate.
*/
ConstBoardIterator::ConstBoardIterator(const BoardInterface* board)
{
  board_ = board;
  i_ = linearize(0,0);
}

/**
* Create a new BoardIterator at a specific location of a board.
*
* @param const BoardInterface* board Board to iterate.
* @param const int x
* @param const int y
*/
ConstBoardIterator::ConstBoardIterator(
  const BoardInterface* board, const int x, const int y
)
{
  board_ = board;
  i_ = linearize(x,y);
}

/**
* Create a new BoardIterator at a specific linearized location of a board.
*
* @param const BoardInterface* board Board to iterate.
* @param const int i
*/
ConstBoardIterator::ConstBoardIterator(const BoardInterface* board, const int i)
{
  board_ = board;
  i_ = i;
}

/**
* Create a new copy of another BoardIterator.
*
* @param const BoardIteratorInterface& toCopy Iterator to copy.
*/
ConstBoardIterator::ConstBoardIterator(const BoardIteratorInterface& toCopy)
{
  board_ = toCopy.board_;
  i_ = toCopy.i_;
}

/**
* Create a new copy of another ConstBoardIterator.
*
* @param const ConstBoardIteratorInterface& toCopy Iterator to copy.
*/
ConstBoardIterator::ConstBoardIterator(
  const ConstBoardIteratorInterface& toCopy
)
{
  board_ = toCopy.board_;
  i_ = toCopy.i_;
}

/**
* Destructor
*/
ConstBoardIterator::~ConstBoardIterator()
{ }

/**
* Get actual iterator x location.
*
* @return int
*/
int ConstBoardIterator::getX() const
{
  return (int) (i_ / board_->getWidth());
}

/**
* Get actual iterator y location.
*
* @return int
*/
int ConstBoardIterator::getY() const
{
  return i_ % board->getWidth();
}

/**
* Return the itered board.
*
* @return BoardIteratorInterface*
*/
const ConstBoardIterator::BoardIteratorInterface* getBoard() const
{
  return board_;
}

/**
* Linearize a 2D location.
*/
int ConstBoardIterator::linearize(const int x, const int y) const
{
  return x * board->getWidth() + y;
}
