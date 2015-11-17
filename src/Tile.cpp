#include "Tile.hpp"

// Constructors
Tile::Tile() {
  board_ = nullptr;
}

Tile::Tile(Board* board){
  board_ = board;
}

Tile::Tile(const TileInterface& toCopy){
  board_ = nullptr;
}

Tile::Tile(const TileInterface& toCopy, Board* board){
	board_ = board;
}

Tile::Tile(const TileInterface& toCopy, Board* board, const int x, const int y){
	board_= board;
	x_= x;
	y_= y;
}

// Destructor
Tile::~Tile()
{ }


// Get Board
const Board* Tile::getBoard() const{
  return board_;
}

Board* Tile::getBoard(){
  return board_;
}


// Get Bot
const Bot* Tile::getBot() const{
  return bot_;
}
  
Bot* Tile::getBot(){
  return bot_;
}

//
bool Tile::isFree() const{
  return (bot_ == nullptr);
}
  
void Tile::onEnter(Bot& bot) {
  bot_ = &bot;
}

void Tile::onExit(Bot& bot) {
  bot_= nullptr;
}


// COPY
gsl::owner<TileInterface*> Tile::copy() const{
	return gsl::owner<Tile*>(new Tile(*this));
}

gsl::owner<TileInterface*> Tile::copy(Board* newParent) const {
  return gsl::owner<Tile* >(new Tile(*this, newParent));
}

gsl::owner<TileInterface*> Tile::copy(
		Board* newParent, 
		const int x, 
		const int y
	  ) const{

	return gsl::owner<Tile*>( new Tile(*this, newParent, x, y));
		  
}


// GET position
int Tile::getX() const{
  return x_;
}

int Tile::getY() const{
  return y_;
}

void Tile::nextTurn(){}
