#ifndef __BOARD_ITERATOR_HPP
#define __BOARD_ITERATOR_HPP

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
    * @TODO operators
    */

  protected:
    int i_;
    BoardInterface* board_;

    /**
    * Linearize a 2D location.
    */
    int linearize(const int x, const int y) const;
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
    * @TODO operators
    */

  protected:
    int i_;
    const BoardInterface* board_;

    /**
    * Linearize a 2D location.
    */
    int linearize(const int x, const int y) const;
};

#endif
