#ifndef __BOARD_ITERATOR_HPP
#define __BOARD_ITERATOR_HPP

#include <iterator>
#include "utils/HorizontalLinearizer2D.hpp"
#include "board/Board.hpp"

/**
* Circular inclusion.
*/
class Board;
class ConstBoardIterator;
class BoardIterator;

/**
* Iterator over tiles.
*
* @class BoardIterator
*/
class BoardIterator :
  public std::iterator<std::input_iterator_tag, TileInterface*>
{
  public:
    /**
    * Create a new BoardIterator at the begining of a board.
    *
    * @param Board* board Board to iterate.
    */
    BoardIterator(Board* board);

    /**
    * Create a new BoardIterator at a specific location of a board.
    *
    * @param Board* board Board to iterate.
    * @param const std::size_t x
    * @param const std::size_t y
    */
    BoardIterator(Board* board, const std::size_t x, const std::size_t y);

    /**
    * Create a new BoardIterator at a specific linearized location of a
    * board.
    *
    * @param Board* board Board to iterate.
    * @param const std::size_t i
    */
    BoardIterator(Board* board, const std::size_t i);

    /**
    * Create a new copy of another BoardIterator.
    *
    * @param BoardIterator& toCopy Iterator to copy.
    */
    BoardIterator(const BoardIterator& toCopy);

    /**
    * Destructor
    */
    virtual ~BoardIterator();

    /**
    * Return the X coordinate of the current position.
    *
    * @return std::size_t
    */
    virtual std::size_t getX() const;

    /**
    * Return the Y coordinate of the current position.
    *
    * @return std::size_t
    */
    virtual std::size_t getY() const;

    /**
    * Return the itered board.
    *
    * @return Board*
    */
    virtual Board* getBoard() const;

    /**
    * Left increment operator.
    */
    virtual BoardIterator& operator++();

    /**
    * Right increment operator
    */
    virtual BoardIterator operator++(const int other);

    /**
    * Dereferencement operator
    */
    virtual TileInterface* operator*() const;

    /**
    * Dereferencement operator
    */
    virtual TileInterface* operator->() const;

    /**
    * Copy assignable
    */
    virtual BoardIterator& operator=(const BoardIterator& other);

    /**
    * Equality operator
    */
    friend bool operator==(
      const BoardIterator& first,
      const BoardIterator& last
    );

    /**
    * Inequality operator
    */
    friend bool operator!=(
      const BoardIterator& first,
      const BoardIterator& last
    );

    /**
    * Equality operator
    */
    friend bool operator==(
      const ConstBoardIterator& first,
      const BoardIterator& last
    );

    /**
    * Inequality operator
    */
    friend bool operator!=(
      const ConstBoardIterator& first,
      const BoardIterator& last
    );

    /**
    * Equality operator
    */
    friend bool operator==(
      const BoardIterator& first,
      const ConstBoardIterator& last
    );

    /**
    * Inequality operator
    */
    friend bool operator!=(
      const BoardIterator& first,
      const ConstBoardIterator& last
    );

  protected:
    Board* board_;
    HorizontalLinearizer2D linearizer_;
    std::size_t i_;

};

/**
* Iterator over const tiles.
*
* @class BoardIterator
*/
class ConstBoardIterator
  : public std::iterator<std::input_iterator_tag, const TileInterface*>
{
  public:
    /**
    * Create a new ConstBoardIterator at the begining of a board.
    *
    * @param const Board* board Board to iterate.
    */
    ConstBoardIterator(const Board* board);

    /**
    * Create a new BoardIterator at a specific location of a board.
    *
    * @param const BoardInterface* board Board to iterate.
    * @param const std::size_t x
    * @param const std::size_t y
    */
    ConstBoardIterator(const Board* board, const std::size_t x, const std::size_t y);

    /**
    * Create a new BoardIterator at a specific linearized location of a board.
    *
    * @param const Board* board Board to iterate.
    * @param const std::size_t i
    */
    ConstBoardIterator(const Board* board, const std::size_t i);

    /**
    * Create a new copy of another BoardIterator.
    *
    * @param const BoardIterator& toCopy Iterator to copy.
    */
    ConstBoardIterator(const BoardIterator& toCopy);

    /**
    * Create a new copy of another ConstBoardIterator.
    *
    * @param const ConstBoardIterator& toCopy Iterator to copy.
    */
    ConstBoardIterator(const ConstBoardIterator& toCopy);

    /**
    * Destructor
    */
    virtual ~ConstBoardIterator();

    /**
    * Return the X coordinate of the current position.
    *
    * @return std::size_t
    */
    virtual std::size_t getX() const;

    /**
    * Return the Y coordinate of the current position.
    *
    * @return std::size_t
    */
    virtual std::size_t getY() const;

    /**
    * Return the itered board.
    *
    * @return const Board*
    */
    virtual const Board* getBoard() const;

    /**
    * Left increment operator.
    */
    virtual ConstBoardIterator& operator++();

    /**
    * Right increment operator
    */
    virtual ConstBoardIterator operator++(const int other);

    /**
    * Dereferencement operator
    */
    virtual const TileInterface* operator*() const;

    /**
    * Dereferencement operator
    */
    virtual const TileInterface* operator->() const;

    /**
    * Copy assignable
    */
    virtual ConstBoardIterator& operator=(const ConstBoardIterator& other);

    /**
    * Copy assignable
    */
    virtual ConstBoardIterator& operator=(const BoardIterator& other);

    /**
    * Equality operator
    */
    friend bool operator==(
      const ConstBoardIterator& first,
      const ConstBoardIterator& last
    );

    /**
    * Inequality operator
    */
    friend bool operator!=(
      const ConstBoardIterator& first,
      const ConstBoardIterator& last
    );

    /**
    * Equality operator
    */
    friend bool operator==(
      const ConstBoardIterator& first,
      const BoardIterator& last
    );

    /**
    * Inequality operator
    */
    friend bool operator!=(
      const ConstBoardIterator& first,
      const BoardIterator& last
    );

    /**
    * Equality operator
    */
    friend bool operator==(
      const BoardIterator& first,
      const ConstBoardIterator& last
    );

    /**
    * Inequality operator
    */
    friend bool operator!=(
      const BoardIterator& first,
      const ConstBoardIterator& last
    );

  protected:
    const Board* board_;
    HorizontalLinearizer2D linearizer_;
    std::size_t i_;
};

#endif
