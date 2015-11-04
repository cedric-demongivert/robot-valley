#include "Tile.hpp"


Tile::Tile(const Board& board){
	board_ = board;
	bot_= nullptr;
}


Tile::Tile(const TileInterface& toCopy){
	board_ = toCopy.getBoard();
	bot_ = toCopy.getBot();
}



const Tile::Board* getBoard() const{
	return const board_;
}

Board* Tile::getBoard(){
	return board_;
}


const Bot* Tile::getBot() const{
	return const bot_;
}
	
	
Bot* Tile::getBot(){
	return bot_;
}


bool Tile::isFree() const{
	return (bot_ == nullptr);
}
	
void Tile::onEnter(Bot& bot){
	
}

void Tile::onExit(Bot& bot) override{
}

Tile* Tile::copy(){
	return Tile(*this);
}
