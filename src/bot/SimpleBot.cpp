#include "bot/SimpleBot.hpp"

/**
* Create a simple bot.
*/
SimpleBot::SimpleBot()
  : location_(Point2D(0, 0)), manager_(nullptr)
{ }

/**
* Create a simple bot with a specific position.
* 
* @param const int x
* @param const int y
*/
SimpleBot::SimpleBot(const int x, const int y)
  : location_(Point2D(x, y)), manager_(nullptr)
{ }

/**
* Copy a generic bot.
* 
* @param const Bot* toCopy
*/
SimpleBot::SimpleBot(const Bot* toCopy)
  : location_(Point2D(*toCopy)), manager_(nullptr)
{ }

/**
* Create a simple bot with a specific position.
*
* @param const Localizable2D&
*/
SimpleBot::SimpleBot(const Localizable2D& position)
  : location_(Point2D(position)), manager_(nullptr)
{ }

/**
* Bot destructor.
*/
SimpleBot::~SimpleBot()
{ }

/**
* Return the x coordinate of that bot on a board.
*
* @return std::size_t x
*/
int SimpleBot::getX() const
{
  return location_.getX();
}

/**
* Return the y coordinate of that bot on a board.
*
* @return std::size_t y
*/
int SimpleBot::getY() const
{
  return location_.getY();
}

/**
* Return the BotManager that manage this robot.
*
* @return BotManager*
*/
BotManager* SimpleBot::getBotManager()
{
  return manager_;
}

/**
* Return the BotManager that manage this robot.
*
* @return const BotManager*
*/
const BotManager* SimpleBot::getBotManager() const
{
  return manager_;
}

/**
* Change the BotManager that manage this robot
*
* @param BotManager* botManager New robot manager.
*/
void SimpleBot::setBotManager(BotManager* botManager)
{
  if (manager_ != botManager) {

    // unregistering from previous game
    if (manager_ != nullptr) {
      BotManager* oldManager = manager_;
      manager_ = nullptr;
      oldManager->removeBot(this);
    }

    manager_ = botManager;

    // registering in new game
    if (manager_ != nullptr) {
      manager_->addBot(this);
    }

  }
}

/**
* Change the location of that bot on the board.
*
* Call that function only if you are a kind of BotManager.
*
* @param const int x New x coordinate of the bot.
* @param const int y New y coordinate of the bot.
*
* @return void
*/
void SimpleBot::setLocation(const int x, const int y)
{
  location_.setLocation(x, y);
}

/**
* Get the tile under the bot.
*
* @return TileInterface*
*/
TileInterface* SimpleBot::getTile()
{
  if (manager_ != nullptr && manager_->getGame() != nullptr) {
    return manager_->getGame()->getBoard()->getTile(*this);
  }
  else {
    return nullptr;
  }
}

/**
* Get the tile under the bot.
*
* @return const TileInterface*
*/
const TileInterface* SimpleBot::getTile() const
{
  if (manager_ != nullptr && manager_->getGame() != nullptr) {
    return manager_->getGame()->getBoard()->getTile(*this);
  }
  else {
    return nullptr;
  }
}

/**
* Pass a turn.
*/
void SimpleBot::nextTurn() {}

