#include "Tile.hpp"

// Constructors
Tile::Tile() {
  board_ = nullptr;
  x_ = y_ = 0;
}

Tile::Tile(Board* board){
  board_ = board;
}

Tile::Tile(const TileInterface& toCopy){
  board_ = nullptr;
  x_ = toCopy.getX();
  y_ = toCopy.getY();
}

Tile::Tile(const TileInterface& toCopy, Board* board){
	board_ = board;
  x_ = toCopy.getX();
  y_ = toCopy.getY();
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

void Tile::setBoard(Board* board)
{
  if (board != board_) {
    Board* oldBoard = board_;
    board_ = nullptr;

    if (oldBoard != nullptr) {
      oldBoard->setTile(x_, y_, nullptr);
    }

    board_ = board;

    if (board_ != nullptr) {
      gsl::owner<TileInterface*> oldTile = board_->setTile(x_, y_, this);
      if (oldTile != nullptr) delete oldTile;
    }

  }
}

// Get Bot
const Bot* Tile::getBot() const
{
  if (this->getBoard() != nullptr && this->getBoard()->getGame() != nullptr) {
    const BotManager* manager = this->getBoard()->getGame()->getBotManager();

    if (manager != nullptr) {
      for (std::size_t index = 0; index < manager->size(); ++index) {
        if (manager->getBot(index)->getX() == getX() && manager->getBot(index)->getY() == getY()) {
          return manager->getBot(index);
        }
      }
    }
  }

  return nullptr;
}
  
Bot* Tile::getBot(){
  if (this->getBoard() != nullptr && this->getBoard()->getGame() != nullptr) {
    BotManager* manager = this->getBoard()->getGame()->getBotManager();

    if (manager != nullptr) {
      for (std::size_t index = 0; index < manager->size(); ++index) {
        if (manager->getBot(index)->getX() == getX() && manager->getBot(index)->getY() == getY()) {
          return manager->getBot(index);
        }
      }
    }
  }

  return nullptr;
}

//
bool Tile::isFree() const{
  return (getBot() == nullptr);
}

bool Tile::accept(const Bot& bot) const {
  return true;
}

void Tile::onEnter(Bot& bot) {

}

void Tile::onExit(Bot& bot) {

}

// COPY
gsl::owner<TileInterface*> Tile::copy() const{
	return gsl::owner<Tile*>(new Tile(*this));
}

// GET position
int Tile::getX() const{
  return x_;
}

int Tile::getY() const{
  return y_;
}

// Change location
void Tile::setLocation(const int x, const int y) {
  if (x_ != x || y_ != y) {
    
    int oldX = x_;
    int oldY = y_;

    x_ = x;
    y_ = y;

    if (board_ != nullptr) {
      board_->setTile(oldX, oldY, nullptr);

      gsl::owner<TileInterface*> oldTile = board_->setTile(x_, y_, this);
      if (oldTile != nullptr) delete oldTile;
    }
  }
}

int Tile::getID() const
{
  return TILE_ID;
}

void Tile::nextTurn(){}
