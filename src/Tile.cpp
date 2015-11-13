#include "Tile.hpp"

Tile::Tile() {
  board_ = nullptr;
}

Tile::Tile(Board* board){
  board_ = board;
}

Tile::Tile(const TileInterface& toCopy){
  board_ = nullptr;
}

Tile::~Tile()
{ }

const Board* Tile::getBoard() const{
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
  bot_ = &bot;
}

void Tile::onExit(Bot& bot) {
  bot_= nullptr;
}

Tile* Tile::copy(Board* newBoard) const {
  return new Tile(*this, newBoard);
}

int Tile::getX() const{
  return X_;
}

int Tile::getY() const{
  return Y_;
}
