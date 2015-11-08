#include "BoardIterator.hpp"

/**
* Create a new BoardIterator at the begining of a board.
*
* @param Board* board Board to iterate.
*/
BoardIterator::BoardIterator(Board* board)
  : board_(board),
    linearizer_(board->getWidth(), board->getHeight()),
    i_(linearizer_.linearize(0,0))
{ }

/**
* Create a new BoardIterator at a specific location of a board.
*
* @param Board* board Board to iterate.
* @param const std::size_t x
* @param const std::size_t y
*/
BoardIterator::BoardIterator(Board* board, const std::size_t x, const std::size_t y)
  : board_(board),
    linearizer_(board->getWidth(), board->getHeight()),
    i_(linearizer_.linearize(x, y))
{ }

/**
* Create a new BoardIterator at a specific linearized location of a board.
*
* @param Board* board Board to iterate.
* @param const std::size_t i
*/
BoardIterator::BoardIterator(Board* board, const std::size_t i)
  : board_(board),
    linearizer_(board->getWidth(), board->getHeight()),
    i_(i)
{ }

/**
* Create a new copy of another BoardIterator.
*
* @param BoardIterator& toCopy Iterator to copy.
*/
BoardIterator::BoardIterator(const BoardIterator& toCopy)
  : board_(toCopy.board_),
    linearizer_(board_->getWidth(), board_->getHeight()),
    i_(toCopy.i_)
{ }

/**
* Destructor
*/
BoardIterator::~BoardIterator()
{ }

/**
* Return the X coordinate of the current position.
*
* @return std::size_t
*/
std::size_t BoardIterator::getX() const
{
  return linearizer_.getX(i_);
}

/**
* Return the Y coordinate of the current position.
*
* @return std::size_t
*/
std::size_t BoardIterator::getY() const
{
  return linearizer_.getY(i_);
}

/**
* Return the itered board.
*
* @return Board*
*/
Board* BoardIterator::getBoard() const
{
  return board_;
}

/**
* Left increment operator.
*/
BoardIterator& BoardIterator::operator++()
{
  if(i_ + 1 < linearizer_.getMaxLinearizedValue()) {
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

  if (i_ + 1 < linearizer_.getMaxLinearizedValue()) {
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
  linearizer_ = HorizontalLinearizer2D(
    board_->getWidth(), board_->getHeight()
  );
  i_ = other.i_;

  return *this;
}

/**
* Equality operator
*/
bool operator==(
  const BoardIterator& first,
  const BoardIterator& last
)
{
  return first.board_ == last.board_ &&
         first.getX() == last.getX() &&
         first.getY() == last.getY();
}

/**
* Inequality operator
*/
bool operator!=(
  const BoardIterator& first,
  const BoardIterator& last
)
{
  return first.board_ != last.board_ ||
         first.getX() != last.getX() ||
         first.getY() != last.getY();
}

/**
* Create a new ConstBoardIterator at the begining of a board.
*
* @param const Board* board Board to iterate.
*/
ConstBoardIterator::ConstBoardIterator(const Board* board)
  : board_(board),
    linearizer_(board->getWidth(), board->getHeight()),
    i_(linearizer_.linearize(0, 0))
{ }

/**
* Create a new ConstBoardIterator at a specific location of a board.
*
* @param const Board* board Board to iterate.
* @param const std::size_t x
* @param const std::size_t y
*/
ConstBoardIterator::ConstBoardIterator(
  const Board* board, const std::size_t x, const std::size_t y
)
  : board_(board),
    linearizer_(board->getWidth(), board->getHeight()),
    i_(linearizer_.linearize(x, y))
{ }

/**
* Create a new ConstBoardIterator at a specific linearized location of a board.
*
* @param const Board* board Board to iterate.
* @param const std::size_t i
*/
ConstBoardIterator::ConstBoardIterator(
  const Board* board, const std::size_t i
)
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
  : board_(toCopy.getBoard()),
    linearizer_(board_->getWidth(), board_->getHeight()),
    i_(linearizer_.linearize(toCopy.getX(), toCopy.getY()))
{ }

/**
* Create a new copy of another ConstBoardIterator.
*
* @param const ConstBoardIterator& toCopy Iterator to copy.
*/
ConstBoardIterator::ConstBoardIterator(
  const ConstBoardIterator& toCopy
)
  : board_(toCopy.board_),
    linearizer_(board_->getWidth(), board_->getHeight()),
    i_(toCopy.i_)
{ }

/**
* Destructor
*/
ConstBoardIterator::~ConstBoardIterator()
{ }

/**
* Return the X coordinate of the current position.
*
* @return std::size_t
*/
std::size_t BoardIterator::getX() const
{
  return linearizer_.getX(i_);
}

/**
* Return the Y coordinate of the current position.
*
* @return std::size_t
*/
std::size_t BoardIterator::getY() const
{
  return linearizer_.getY(i_);
}

/**
* Return the itered board.
*
* @return const Board*
*/
const Board* ConstBoardIterator::getBoard() const
{
  return board_;
}

/**
* Right increment operator
*/
ConstBoardIterator ConstBoardIterator::operator++(const int other)
{
  ConstBoardIterator notModified (*this);

  if(i_ + 1 < linearizer_.getMaxLinearizedValue()) {
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
ConstBoardIterator& ConstBoardIterator::operator=(const ConstBoardIterator& other)
{
  if(&other == this) return *this;

  board_ = other.board_;
  linearizer_ = HorizontalLinearizer2D(board_->getWidth(), board_->getHeight());
  i_ = other.i_;

  return *this;
}

/**
* Copy assignable
*/
ConstBoardIterator& ConstBoardIterator::operator=(const BoardIterator& other)
{
  board_ = other.getBoard();
  linearizer_ = HorizontalLinearizer2D(board_->getWidth(), board_->getHeight());
  i_ = linearizer_.linearize(other.getX(), other.getY());

  return *this;
}

/**
* Equality operator
*/
bool operator==(
  const ConstBoardIterator& first,
  const ConstBoardIterator& last
)
{
  return first.board_ == last.board_ &&
         first.getX() == last.getX() &&
         first.getY() == last.getY();
}

/**
* Inequality operator
*/
bool operator!=(
  const ConstBoardIterator& first,
  const ConstBoardIterator& last
)
{
  return first.board_ != last.board_ ||
         first.getX() != last.getX() ||
         first.getY() != last.getY();
}

/**
* Equality operator
*/
bool operator==(
  const ConstBoardIterator& first,
  const BoardIterator& last
  )
{
  return first.board_ == last.board_ &&
    first.getX() == last.getX() &&
    first.getY() == last.getY();
}

/**
* Inequality operator
*/
bool operator!=(
  const ConstBoardIterator& first,
  const BoardIterator& last
  )
{
  return first.board_ != last.board_ ||
    first.getX() != last.getX() ||
    first.getY() != last.getY();
}

/**
* Equality operator
*/
bool operator==(
  const BoardIterator& first,
  const ConstBoardIterator& last
  )
{
  return first.board_ == last.board_ &&
    first.getX() == last.getX() &&
    first.getY() == last.getY();
}

/**
* Inequality operator
*/
bool operator!=(
  const BoardIterator& first,
  const ConstBoardIterator& last
  )
{
  return first.board_ != last.board_ ||
    first.getX() != last.getX() ||
    first.getY() != last.getY();
}