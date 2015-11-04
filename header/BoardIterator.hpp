#ifndef __BOARD_ITERATOR_HPP
#define __BOARD_ITERATOR_HPP

#include "BoardIteratorInterface.hpp"

/**
* Iterator over tiles.
*
* @class BoardIterator
*/
class BoardIterator : public BoardIteratorInterface
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
    * @param BoardIteratorInterface& toCopy Iterator to copy.
    */
    BoardIterator(const BoardIteratorInterface& toCopy);

    /**
    * Destructor
    */
    virtual ~BoardIterator();

    /**
    * Get actual iterator x location.
    *
    * @return int
    */
    virtual int getX() const override;

    /**
    * Get actual iterator y location.
    *
    * @return int
    */
    virtual int getY() const override;

    /**
    * Return the itered board.
    *
    * @return BoardIteratorInterface*
    */
    virtual BoardIteratorInterface* getBoard() const override;

    /**
    * @TODO operators
    */

  protected:
    int i_;
    BoardInterface* board_;

    /**
    * Linearize a 2D location.
    */
    int linearize(const int x, const int y) const;
}

/**
* Iterator over const tiles.
*
* @class BoardIterator
*/
class ConstBoardIterator : public ConstBoardIteratorInterface
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
    * @param const BoardIteratorInterface& toCopy Iterator to copy.
    */
    ConstBoardIterator(const BoardIteratorInterface& toCopy);

    /**
    * Create a new copy of another ConstBoardIterator.
    *
    * @param const ConstBoardIteratorInterface& toCopy Iterator to copy.
    */
    ConstBoardIterator(const ConstBoardIteratorInterface& toCopy);

    /**
    * Destructor
    */
    virtual ~ConstBoardIterator();
    /**
    * Get actual iterator x location.
    *
    * @return int
    */
    virtual int getX() const override;

    /**
    * Get actual iterator y location.
    *
    * @return int
    */
    virtual int getY() const override;

    /**
    * Return the itered board.
    *
    * @return BoardIteratorInterface*
    */
    virtual const BoardIteratorInterface* getBoard() const override;

    /**
    * @TODO operators
    */

  protected:
    int i_;
    const BoardInterface* board_;

    /**
    * Linearize a 2D location.
    */
    int linearize(const int x, const int y) const;
}

#endif
