#ifndef __BOARD_HPP
#define __BOARD_HPP

#include "GSL/gsl.h"
#include <stdexcept>
#include "utils/Linearizer2D.hpp"
#include "mixins/Copiable.hpp"
#include "TileInterface.hpp"
#include "game/Game.hpp"
#include "board/BoardIterator.hpp"

/**
* Circular inclusion.
*/
class TileInterface;
class BoardIterator;
class ConstBoardIterator;
class Game;

/**
* @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*
* This class define a board that is a rectangular array of tiles.
*
* @class Board
*/
class Board
  : public Copiable<Board>
{
  public:
    /**
    * Board destructor.
    */
    virtual ~Board() { }

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
    * Return the x coordinate of the first tile in that board.
    *
    * @return int
    */
    virtual int getX() const = 0;

    /**
    * Return the y coordinate of the first tile in that board.
    *
    * @return int
    */
    virtual int getY() const = 0;

    /**
    * Return a begin iterator over this board.
    *
    * @return BoardIterator
    */
    virtual BoardIterator begin() = 0;
    
    /**
    * Return a begin iterator over this board.
    *
    * @return ConstBoardIterator
    */
    virtual ConstBoardIterator begin() const = 0;

    /**
    * Return an end iterator over this board.
    *
    * @return ConstBoardIterator
    */
    virtual BoardIterator end() = 0;
    
    /**
    * Return an end iterator over this board.
    *
    * @return ConstBoardIterator
    */
    virtual ConstBoardIterator end() const = 0;

    /**
    * Return a tile at a specific location.
    *
    * @param const int x
    * @param const int y
    *
    * @throws std::out_of_range If the location (x,y) do not exist.
    *
    * @return TileInterface* Tile at the (x,y) location, while return nullptr if
    *                        the tile do not exist.
    */
    virtual TileInterface* getTile(
      const int x,
      const int y
    ) = 0;

    /**
    * Return a tile at a specific location.
    *
    * @param const int x
    * @param const int y
    *
    * @throws std::out_of_range If the location (x,y) do not exist.
    *
    * @return const TileInterface* Tile at the (x,y) location, while return nullptr if
    *                        the tile do not exist.
    */
    virtual const TileInterface* getTile(
      const int x,
      const int y
    ) const = 0;

    /**
    * Return a tile at a specific location.
    *
    * @param const Localizable2D& location
    *
    * @throws std::out_of_range If the location (x,y) do not exist.
    *
    * @return TileInterface* Tile at the (x,y) location, while return nullptr if
    *                        the tile do not exist.
    */
    inline TileInterface* getTile(
      const Localizable2D& location
    ) {
      return getTile(location.getX(), location.getY());
    }

    /**
    * Return a tile at a specific location.
    *
    * @param const Localizable2D& location
    *
    * @throws std::out_of_range If the location (x,y) do not exist.
    *
    * @return TileInterface* Tile at the (x,y) location, while return nullptr if
    *                        the tile do not exist.
    */
    inline const TileInterface* getTile(
      const Localizable2D& location
    ) const
    {
      return getTile(location.getX(), location.getY());
    }

    /**
    * Set a tile in a specific location.
    *
    * If a tile already exist at the location, this object will destroy it.
    *
    * @param const int x
    * @param const int y
    * @param gsl::owner<TileInterface*> tile Tile to set.
    *
    * @throws std::out_of_range If the location (x,y) do not exist.
    *
    * @return gsl::owner<TileInterface*> Old tile
    */
    virtual gsl::owner<TileInterface*> setTile(
      const int x,
      const int y,
      gsl::owner<TileInterface*> tile
    ) = 0;

    /**
    * Set a tile in a specific location.
    *
    * If a tile already exist at the location, this object will destroy it.
    *
    * @param const Localizable2D& location
    * @param gsl::owner<TileInterface*> tile Tile to set.
    *
    * @throws std::out_of_range If the location (x,y) do not exist.
    *
    * @return void
    */
    inline void setTile(
      const Localizable2D& location,
      gsl::owner<TileInterface*> tile
    ) {
      setTile(location.getX(), location.getY(), tile);
    }

    /**
    * Check if a location is in the board.
    *
    * @param const int x
    * @param const int y
    *
    * @return bool True if the (x,y) location is in the board.
    */
    virtual bool contains(
      const int x,
      const int y
    ) const = 0;
    
    /**
     * Return the Game that use that board.
     * 
     * @return Game* game
     */
    virtual Game* getGame() = 0;
    
    /**
     * Return the Game that use that board.
     * 
     * @return const Game* game
     */
    virtual const Game* getGame() const = 0;
    
    /**
     * Change the Game that use that board.
     * 
     * @return Game* game
     */
    virtual void setGame(Game* game) = 0;

    /**
    * Check if a location is in the board.
    *
    * @param const Localizable2D& location
    *
    * @return bool True if the (x,y) location is in the board.
    */
    inline bool contains(
      const Localizable2D& location
    ) const
    {
      return contains(location.getX(), location.getY());
    }

    /**
     * Pass a turn.
     */
    virtual void nextTurn() = 0;
    
    /**
     * Allocate a new copy of this board.
     */
    virtual gsl::owner<Board*> copy() const override = 0; 
};

#endif
