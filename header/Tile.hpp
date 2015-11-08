#ifndef __TILE_HPP
#define __TILE_HPP

#include "TileInterface.hpp"

class Board;
class Bot;



/**
 *	@author K/OURIO Alexandre <kourio.alexandre@gmail.com>
 * 
 * 	A basic Tile that implement TileInterface.
 * 
 * 	@class TileInterface
 */
 
class Tile: public TileInterface{

public:

	Tile(Board* board);
	Tile(const TileInterface& toCopy, Board* board);

  virtual ~Tile() override;

  virtual const Board* getBoard() const override;
  virtual Board* getBoard() override;

  virtual const Bot* getBot() const override;
  virtual Bot* getBot() override;

  virtual bool isFree() const override;

  virtual void onEnter(Bot& bot) override;
  virtual void onExit(Bot& bot) override;

  virtual Tile* copy(Board* newBoard) const override;

private:
	Board* board_;
	Bot* bot_;
};

#endif
