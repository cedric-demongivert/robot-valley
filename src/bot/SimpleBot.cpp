#include "bot/SimpleBot.hpp"

/**
* Create a simple bot.
*/
SimpleBot()
  : x_(0), y_(0), tile_(nullptr)
{ }

/**
* Create a simple bot with a specific position.
* 
* @param const std::size_t x
* @param const std::size_t y
*/
SimpleBot(const std::size_t x, const std::size_t y)
  : x_(x), y_(y), tile_(nullptr)
{ }

/**
* Create a bot on a tile.
* 
* @param TileInterface* tile
*/
SimpleBot(const gsl::not_null<TileInterface*> tile)
  : x_(tile->getX()), y_(tile->getY()), tile_(tile)
{ }

/**
* Copy a generic bot.
* 
* @param const Bot* toCopy
*/
SimpleBot(const Bot* toCopy)
  : x_(toCopy->getX()), y_(toCopy->getY()), tile_(nullptr)
{ }

