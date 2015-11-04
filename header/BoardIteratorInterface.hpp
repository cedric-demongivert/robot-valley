#ifndef __BOARD_ITERATOR_INTERFACE_HPP
#define __BOARD_ITERATOR_INTERFACE_HPP

#include <iterator>
#include "BoardInterface.hpp"
#include "TileInterface.hpp"

/**
* Circular inclusion.
*/
class BoardInterface;

/**
* Iterator over tiles.
*
* @class BoardIteratorInterface
*/
class BoardIteratorInterface
  : public std::iterator<std::input_iterator_tag, TileInterface*>
{
  /**
  * Get actual iterator x location.
  *
  * @return int
  */
  virtual int getX() const = 0;

  /**
  * Get actual iterator y location.
  *
  * @return int
  */
  virtual int getY() const = 0;

  /**
  * Return the itered board.
  *
  * @return BoardIteratorInterface*
  */
  virtual BoardIteratorInterface* getBoard() const = 0;
}

/**
* Iterator over const tiles.
*
* @class ConstBoardIteratorInterface
*/
class ConstBoardIteratorInterface
  : public std::iterator<std::input_iterator_tag, const TileInterface*>
{
  /**
  * Get actual iterator x location.
  *
  * @return int
  */
  virtual int getX() const = 0;

  /**
  * Get actual iterator y location.
  *
  * @return int
  */
  virtual int getY() const = 0;

  /**
  * Return the itered board.
  *
  * @return BoardIteratorInterface*
  */
  virtual const BoardIteratorInterface* getBoard() const = 0;
}

#endif
