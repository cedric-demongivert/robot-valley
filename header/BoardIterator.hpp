#ifndef __BOARD_ITERATOR_HPP
#define __BOARD_ITERATOR_HPP

#include <iterator>
#include "BoardInterface.hpp"

/**
* Circular inclusion.
*/
class BoardInterface;

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
    * @param BoardInterface* board Board to iterate.
    */
    BoardIterator(BoardInterface* board);

    /**
    * Create a new BoardIterator at a specific location of a board.
    *
    * @param BoardInterface* board Board to iterate.
    * @param const int x
    * @param const int y
    */
    BoardIterator(BoardInterface* board, const int x, const int y);

    /**
    * Create a new BoardIterator at a specific linearized location of a
    * board.
    *
    * @param BoardInterface* board Board to iterate.
    * @param const int i
    */
    BoardIterator(BoardInterface* board, const int i);

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
    * Get actual iterator x location.
    *
    * @return int
    */
    virtual int getX() const;

    /**
    * Get actual iterator y location.
    *
    * @return int
    */
    virtual int getY() const;

    /**
    * Return the itered board.
    *
    * @return BoardInterface*
    */
    virtual BoardInterface* getBoard() const;

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

  protected:
    int i_;
    BoardInterface* board_;

    /**
    * Linearize a 2D location.
    */
    int linearize(const int x, const int y) const;

    /**
    * Return the maximum position of this iterator.
    */
    int max() const;
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
    * Create a new BoardIterator at the begining of a board.
    *
    * @param const BoardInterface* board Board to iterate.
    */
    ConstBoardIterator(const BoardInterface* board);

    /**
    * Create a new BoardIterator at a specific location of a board.
    *
    * @param const BoardInterface* board Board to iterate.
    * @param const int x
    * @param const int y
    */
    ConstBoardIterator(const BoardInterface* board, const int x, const int y);

    /**
    * Create a new BoardIterator at a specific linearized location of a board.
    *
    * @param const BoardInterface* board Board to iterate.
    * @param const int i
    */
    ConstBoardIterator(const BoardInterface* board, const int i);

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
    * Get actual iterator x location.
    *
    * @return int
    */
    virtual int getX() const;

    /**
    * Get actual iterator y location.
    *
    * @return int
    */
    virtual int getY() const;

    /**
    * Return the itered board.
    *
    * @return BoardInterface*
    */
    virtual const BoardInterface* getBoard() const;

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

  protected:
    int i_;
    const BoardInterface* board_;

    /**
    * Linearize a 2D location.
    */
    int linearize(const int x, const int y) const;

    /**
    * Return the maximum position of this iterator.
    */
    int max() const;
};

#endif
