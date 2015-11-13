#ifndef __TILE_HPP
#define __TILE_HPP

#include "TileInterface.hpp"
#include "board/Board.hpp"

class Bot;

/**
 *  @author K/OURIO Alexandre <kourio.alexandre@gmail.com>
 * 
 *  A basic Tile that implement TileInterface.
 * 
 *  @class TileInterface
 */
 
class Tile: public TileInterface{

public:
  Tile();
  Tile(Board* board);
  Tile(const TileInterface& toCopy);

  virtual ~Tile();

  const Board* getBoard() const;
  Board* getBoard() ;

  const Bot* getBot() const ;
  Bot* getBot();

  bool isFree() const;

  virtual void onEnter(Bot& bot);
  virtual void onExit(Bot& bot);

  virtual Tile* copy() const;

private:
  Board* board_;
};

#endif
