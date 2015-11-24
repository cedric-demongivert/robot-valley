#include "bot/StupidBot.hpp"

/**
* Create a simple bot.
*/
StupidBot::StupidBot() : SimpleBot() {}

/**
* Create a simple bot with a specific position.
*
* @param const int x
* @param const int y
*/
StupidBot::StupidBot(const int x, const int y) : SimpleBot(x,y) {}

/**
* Create a simple bot with a specific position.
*
* @param const Localizable2D&
*/
StupidBot::StupidBot(const Localizable2D& position) : SimpleBot(position) {}

/**
* Copy a generic bot.
*
* @param const Bot* toCopy
*/
StupidBot::StupidBot(const Bot* toCopy) : SimpleBot(toCopy) {}

/**
* Bot destructor.
*/
StupidBot::~StupidBot() {}

/**
* Pass a turn.
*/
void StupidBot::nextTurn()
{
  setY(getY() + 1);
} 

/**
* Allocate a copy of that bot.
*
* @return gsl::owner<Bot*>
*/
gsl::owner<Bot*> StupidBot::copy() const
{
  return new StupidBot(*this);
}