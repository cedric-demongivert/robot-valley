#ifndef __BOARD_INTERFACE_HPP
#define __BOARD_INTERFACE_HPP

#include "TileInterface.hpp"
#include "BoardIteratorInterface.hpp"

/**
* Circular inclusion.
*/
class TileInterface;
class BoardIteratorInterface;
class ConstBoardIteratorInterface;

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
    * @return BoardInterface::BoardIteratorInterface
    */
    virtual BoardIteratorInterface begin() = 0;
    virtual ConstBoardIteratorInterface begin() const = 0;

    /**
    * Return an end iterator over this board.
    *
    * @return BoardInterface::ConstBoardIteratorInterface
    */
    virtual BoardIteratorInterface end() = 0;
    virtual ConstBoardIteratorInterface end() const = 0;

    /**
    * Return a tile at a specific location.
    *
    * @param const int x
    * @param const int y
    *
    * @throws BoardOutOfBoundsException If the location (x,y) do not exist.
    *
    * @return TileInterface* Tile at the (x,y) location, while return nullptr if
    *                        the tile do not exist.
    */
    virtual TileInterface* getTile(const int x, const int y) = 0;
    virtual const TileInterface* getTile(const int x, const int y) const = 0;

    /**
    * Set a tile in a specific location.
    *
    * If a tile already exist at the location, this object will destroy it.
    *
    * @param const int x
    * @param const int y
    * @param TileInterface* tile Tile to set.
    *
    * @throws BoardOutOfBoundsException If the location (x,y) do not exist.
    *
    * @return void
    */
    virtual void setTile(const int x, const int y, TileInterface* tile);

    /**
    * Check if a location is in the board.
    *
    * @param const int x
    * @param const int y
    *
    * @return bool True if the (x,y) location is in the board.
    */
    virtual bool isIn(const int x, const int y) const;
};

#endif
