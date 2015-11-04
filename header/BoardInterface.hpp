#ifndef __BOARD_INTERFACE_HPP
#define __BOARD_INTERFACE_HPP

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
* This class define a board that is rectangular and store tiles.
*
* @class BoardInterface
*/
class BoardInterface
{
  public:
    /**
    * Board destructor, the board will destroy its tiles.
    */
    virtual ~BoardInterface() = 0;

    /**
    * Retourne la hauteur du tableau.
    *
    * @return size_t Hauteur du tableau.
    */
    virtual std::size_t getHeight() const = 0;

    /**
    * Retourne la largeur du tableau.
    *
    * @return size_t Largeur du tableau.
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
    * @throws BoardOutOfBoundsException If the location (x,y) do not exist.
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
    * @param TileInterface* tile Tile to set.
    *
    * @throws BoardOutOfBoundsException If the location (x,y) do not exist.
    *
    * @return void
    */
    virtual void setTile(
      const std::size_t x,
      const std::size_t y,
      TileInterface* tile
    );

    /**
    * Check if a location is in the board.
    *
    * @param const std::size_t x
    * @param const std::size_t y
    *
    * @return bool True if the (x,y) location is in the board.
    */
    virtual bool isIn(
      const std::size_t x,
      const std::size_t y
    ) const;
};

#endif
