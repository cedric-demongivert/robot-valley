#ifndef __TILE_INTERFACE_HPP
#define __TILE_INTERFACE_HPP

#include <cstdlib>
#include "mixins/Localizable2D.hpp"
#include "mixins/Copiable.hpp"
#include "mixins/Movable2D.hpp"
#include "GSL/gsl.h"

/**
 * @author K/OURIO Alexandre <kourio.alexandre@gmail.com>
 * */
class BoardInterface;
class Board;
class Bot;


class TileInterface : public Localizable2D, public Movable2D, public Copiable<TileInterface>{
public:
  /**
   * Destructor.
   */
  virtual ~TileInterface()
  { };

  /**
   *  Return the board that contain this tile.
   *
   *  @return const Board*
   */
  virtual const Board* getBoard() const = 0;
  
  /**
   *  Return the board that contain this tile.
   *
   *  @return Board*
   */
  virtual Board* getBoard() = 0;

  /**
  *  Change the board that contain this tile.
  *
  *  @return Board*
  */
  virtual void setBoard(Board* newBoard) = 0;

  /**
   *  Get the bot on the tile
   *
   *  @return const Bot* or nullptr if no bot on the tile
   */
  virtual const Bot* getBot() const = 0;
  
  /**
   *  Get the bot on the tile
   *
   *  @return Bot* or nullptr if no bot on the tile
   */
  virtual Bot* getBot() = 0;

  /**
   *  If there is nothing on the tile
   *
   *  @return bool
   */
  virtual bool isFree() const = 0;

  /**
   *  Called when a bot enters the tile
   *
   *  @throws TileNotFreeException - the tile isn't free.
   *
   *  @param Bot& bot The bot that enters the tile
   */
  virtual void onEnter(Bot& bot) = 0;

  /**
   *  Called when a bot leaves the tile
   *
   *  @throws TileFreeException - No Bot on tile so it can't leave it
   *
   *  @param Bot& bot The bot that leaves the tile
   */
  virtual void onExit(Bot& bot) = 0;

  /**
   *  Return a copy of this tile
   *
   *  @return TileInterface* - A real copy of the tile
   */
  virtual gsl::owner<TileInterface*> copy() const override =0;
  
  /**
  * Get the tile location in its board.
  */
  virtual int getX() const override = 0;
  virtual int getY() const override = 0;

  /**
  * Set the tile location in its board.
  */
  virtual void setX(const int x) override = 0;
  virtual void setY(const int x) override = 0;
  virtual void setLocation(const int x, const int y) override = 0;

  virtual void nextTurn() = 0;
  	
  	  
};

#endif
