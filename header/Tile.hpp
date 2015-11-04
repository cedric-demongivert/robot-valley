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

	Tile(const Board& board);
	Tile(const TileInterface& toCopy);

	~Tile() override;

	const Board* getBoard() const override;
	Board* getBoard() override;

	const Bot* getBot() const override;
	Bot* getBot() override;

	bool isFree() const override;

	void onEnter(Bot& bot) override;
	void onExit(Bot& bot) override;

	Tile* copy() override;


private:
	Board* board_;
	Bot* bot_;
};

#endif
