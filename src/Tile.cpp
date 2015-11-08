#include "Tile.hpp"


Tile::Tile(Board* board){
	board_ = board;
	bot_= nullptr;
}


Tile::Tile(const TileInterface& toCopy, Board* newBoard){
  board_ = newBoard;
	bot_ = nullptr;
}

const Board* Tile::getBoard() const
{
	return board_;
}

Board* Tile::getBoard(){
	return board_;
}


const Bot* Tile::getBot() const{
	return bot_;
}
	
	
Bot* Tile::getBot(){
	return bot_;
}


bool Tile::isFree() const{
	return (bot_ == nullptr);
}
	
void Tile::onEnter(Bot& bot) {
	
}

void Tile::onExit(Bot& bot) {
}

Tile* Tile::copy(Board* newBoard) const {
	return new Tile(*this, newBoard);
}
