#include "bot/VectorBotManager.hpp"
/**
 * @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
 */

/**
 * Create an empty BotManager.
 */
VectorBotManager::VectorBotManager()
{ }

/**
 * Create a deep-copy of an existing BotManager.
 * 
 * @param const BotManager& manager
 */
VectorBotManager::VectorBotManager(const BotManager& manager)
{
  for(Bot* bot : manager)
  {
    bots_.push_back(bot->copy());
  }
}

/**
 * Destructor.
 */
VectorBotManager::~VectorBotManager()
{ 
  while(!bots_.empty())
  {
    gsl::owner<Bot*> bot = bots_.pop_back();
    delete bot;
  }
};

/**
 * Return a bot of the BotManager.
 * 
 * @throw std::out_of_range If index is out of range.
 * 
 * @param const std::size_t index
 * 
 * @return Bot*
 */
Bot* VectorBotManager::getBot(const std::size_t index)
{
  return bots_[index];
}

/**
 * Return a bot of the BotManager.
 * 
 * @throw std::out_of_range If index is out of range.
 * 
 * @param const std::size_t index
 * 
 * @return const Bot*
 */
const Bot* VectorBotManager::getBot(const std::size_t index) const
{
  return bots_[index];
}

/**
 * Return the bot count.
 * 
 * @return std::size_t
 */
std::size_t VectorBotManager::size() const
{
  return bots_.size();
}

/**
 * Add a bot to the manager.
 * 
 * @param gsm::owner<Bot*> bot
 */
void VectorBotManager::addBot(gsl::owner<Bot*> bot)
{
  bots_.push_back(bot);
}

/**
 * Delete a bot of the BotManager.
 * 
 * @throw std::out_of_range If index is out of range.
 * 
 * @param const std::size_t index
 */
void VectorBotManager::removeBot(const std::size_t index)
{
  gsl::owner<Bot*> bot = bots_[index];
  bots_[index] = bots_[bots_.size() -1];
  bots_[bots_.size() -1] = bot;
  
  bot = bots_.pop_back();
  delete bot;
}

/**
 * Return an iterator at the begining of the bot collection.
 * 
 * @return BotIterator
 */
BotIterator VectorBotManager::begin()
{
  return bots_.begin();
}

/**
 * Return an iterator at the begining of the bot collection.
 * 
 * @return ConstBotIterator
 */
ConstBotIterator VectorBotManager::begin() const
{
  return bots_.begin();
}

/**
 * Return an iterator at the end of the bot collection.
 * 
 * @return BotIterator
 */
BotIterator VectorBotManager::end()
{
  return bots_.end();
}

/**
 * Return an iterator at the end of the bot collection.
 * 
 * @return ConstBotIterator
 */
ConstBotIterator VectorBotManager::end() const
{
  return bots_.end();
}

/**
 * Return a deep-copy of this manager.
 * 
 * @return gsl::owner<BotManager*>
 */
gsl::owner<BotManager*> VectorBotManager::copy() const
{
  return gsl::owner<BotManager*>(new VectorBotManager(*this));
}

/**
 * Pass a turn.
 */
void VectorBotManager::nextTurn()
{
  for(Bot* bot : *this) {
    bot->nextTurn();
  }
}

#endif
