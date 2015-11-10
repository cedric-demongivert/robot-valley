#ifndef __TILE_HPP
#define __TILE_HPP

#include "TileInterface.hpp"
#include "board/Board.hpp"

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

	virtual ~Tile();

	virtual const Board* getBoard() const;
	virtual Board* getBoard() ;

	virtual const Bot* getBot() const ;
	virtual Bot* getBot();

	virtual bool isFree() const;

	virtual void onEnter(Bot& bot);
	virtual void onExit(Bot& bot);

	virtual Tile* copy(Board* newBoard) const;

private:
	Board* board_;
	Bot* bot_;
};

#endif
