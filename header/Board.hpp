#ifndef __BOARD_INTERFACE_HPP
#define __BOARD_INTERFACE_HPP

#include "GSL/gsl.h"
#include <stdexcept>
#include "Linearizer2D.hpp"
#include "TileInterface.hpp"
#include "BoardIterator.hpp"

/**
* Circular inclusion.
*/
class TileInterface;
class BoardIterator;
class ConstBoardIterator;

/**
* @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*
* This class define a board that is a rectangular array of tiles.
*
* @class Board
*/
class Board
{
  public:
    /**
    * Board destructor.
    */
    virtual ~Board() = 0;

    /**
    * Return the board height
    *
    * @return std::size_t
    */
    virtual std::size_t getHeight() const = 0;

    /**
    * Return the board width.
    *
    * @return std::size_t
    */
    virtual std::size_t getWidth() const = 0;

    /**
    * Return a begin iterator over this board.
    *
    * @return BoardIterator
    */
    virtual BoardIterator begin() = 0;
    virtual ConstBoardIterator begin() const = 0;

    /**
    * Return an end iterator over this board.
    *
    * @return ConstBoardIterator
    */
    virtual BoardIterator end() = 0;
    virtual ConstBoardIterator end() const = 0;

    /**
    * Return a tile at a specific location.
    *
    * @param const std::size_t x
    * @param const std::size_t y
    *
    * @throws std::out_of_range If the location (x,y) do not exist.
    *
    * @return TileInterface* Tile at the (x,y) location, while return nullptr if
    *                        the tile do not exist.
    */
    virtual TileInterface* getTile(
      const std::size_t x,
      const std::size_t y
    ) = 0;

    virtual const TileInterface* getTile(
      const std::size_t x,
      const std::size_t y
    ) const = 0;

    /**
    * Set a tile in a specific location.
    *
    * If a tile already exist at the location, this object will destroy it.
    *
    * @param const std::size_t x
    * @param const std::size_t y
    * @param gsl::owner<TileInterface*> tile Tile to set.
    *
    * @throws std::out_of_range If the location (x,y) do not exist.
    *
    * @return void
    */
    virtual void setTile(
      const std::size_t x,
      const std::size_t y,
      gsl::owner<TileInterface*> tile
    ) = 0;

    /**
    * Check if a location is in the board.
    *
    * @param const std::size_t x
    * @param const std::size_t y
    *
    * @return bool True if the (x,y) location is in the board.
    */
    virtual bool contains(
      const std::size_t x,
      const std::size_t y
    ) const = 0;

};

#endif
