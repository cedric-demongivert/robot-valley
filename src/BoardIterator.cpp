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
* @param BoardIterator& toCopy Iterator to copy.
*/
BoardIterator::BoardIterator(const BoardIterator& toCopy)
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
int BoardIteratorCommon::getX() const
{
  return (int)(i_ / board->getWidth());
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
* @return BoardInterface*
*/
BoardInterface* BoardIterator::getBoard() const
{
  return board_
}

/**
* Left increment operator.
*/
BoardIterator& BoardIterator::operator++()
{
  if(i + 1 < max()) {
    i_ += 1;
  }

  return *this;
}

/**
* Right increment operator.
*/
BoardIterator BoardIterator::operator++(const int other)
{
  BoardIterator notModified (*this);

  if(i + 1 < max()) {
    i_ += 1;
  }

  return notModified;
}

/**
* Dereferencement operator
*/
TileInterface* BoardIterator::operator*() const
{
  return board_->getTile(getX(), getY());
}

/**
* Dereferencement operator
*/
TileInterface* BoardIterator::operator->() const
{
  return board_->getTile(getX(), getY());
}

/**
* Copy assignable
*/
BoardIterator& BoardIterator::operator=(const BoardIterator& other)
{
  if(&other == this) return *this;

  board_ = other.board_;
  i_ = other.i_;

  return *this;
}

/**
* Equality operator
*/
friend bool operator==(
  const BoardIterator& first,
  const BoardIterator& last
)
{
  return first.board_ == last.board_ &&
         first.i_ == last.i_;
}

/**
* Inequality operator
*/
friend bool operator!=(
  const BoardIterator& first,
  const BoardIterator& last
)
{
  return first.board_ != last.board_ ||
         first.i_ != last.i_;
}

/**
* Linearize a 2D location.
*/
int BoardIterator::linearize(const int x, const int y) const
{
  return x * board_->getWidth() + y;
}

/**
* Return the maximum position of this iterator.
*/
int BoardIterator::max() const
{
  return board_->getWidth() * board_->getHeight() + 1;
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
* @param const BoardIterator& toCopy Iterator to copy.
*/
ConstBoardIterator::ConstBoardIterator(const BoardIterator& toCopy)
{
  board_ = toCopy.board_;
  i_ = toCopy.i_;
}

/**
* Create a new copy of another ConstBoardIterator.
*
* @param const ConstBoardIterator& toCopy Iterator to copy.
*/
ConstBoardIterator::ConstBoardIterator(
  const ConstBoardIterator& toCopy
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
* @return BoardInterface*
*/
const BoardInterface* ConstBoardIterator::getBoard() const
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

/**
* Left increment operator.
*/
ConstBoardIterator& ConstBoardIterator::operator++()
{
  if(i + 1 < max()) {
    i_ += 1;
  }

  return notModified;
}

/**
* Right increment operator
*/
ConstBoardIterator ConstBoardIterator::operator++(const int other)
{
  ConstBoardIterator notModified (*this);

  if(i + 1 < max()) {
    i_ += 1;
  }

  return notModified;
}

/**
* Dereferencement operator
*/
const TileInterface* ConstBoardIterator::operator*() const
{
  return board_->getTile(getX(), getY());
}

/**
* Dereferencement operator
*/
const TileInterface* ConstBoardIterator::operator->() const
{
  return board_->getTile(getX(), getY());
}

/**
* Copy assignable
*/
ConstBoardIterator& operator=(const ConstBoardIterator& other)
{
  if(&other == this) return *this;

  board_ = other.board_;
  i_ = other.i_;

  return *this;
}

/**
* Equality operator
*/
friend bool operator==(
  const ConstBoardIterator& first,
  const ConstBoardIterator& last
)
{
  return first.board_ == last.board_ &&
         first.i_ == last.i_;
}

/**
* Inequality operator
*/
friend bool operator!=(
  const ConstBoardIterator& first,
  const ConstBoardIterator& last
)
{
  return first.board_ != last.board_ ||
         first.i_ == last.i_;
}

/**
* Return the maximum position of this iterator.
*/
int ConstBoardIterator::max() const
{
  return board_->getWidth() * board_->getHeight() + 1;
}
