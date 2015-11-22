#include "bot/VectorBotManager.hpp"
/**
 * @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
 */

/**
 * Create an empty BotManager.
 */
VectorBotManager::VectorBotManager()
  : game_(nullptr)
{ }

/**
 * Create a deep-copy of an existing BotManager.
 * 
 * @param const BotManager& manager
 */
VectorBotManager::VectorBotManager(const BotManager& manager)
  : game_(nullptr)
{
  for(std::size_t index = 0; index < manager.size(); ++index)
  {
    addBot(manager.getBot(index)->copy());
  }
}

/**
 * Destructor.
 */
VectorBotManager::~VectorBotManager()
{
  for (gsl::owner<Bot*> bot : bots_) {
    delete bot;
  }
}

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
  if (!this->contains(bot)) {
    bots_.push_back(bot);
    bot->setBotManager(this);
  }
}

/**
 * Delete a bot of the BotManager.
 * 
 * @throw std::out_of_range If index is out of range.
 * 
 * @param const std::size_t index
 */
gsl::owner<Bot*> VectorBotManager::removeBot(const std::size_t index)
{
  gsl::owner<Bot*> bot = bots_[index];
  bots_[index] = bots_[bots_.size() -1];
  bots_[bots_.size() -1] = bot;
  
  bot = bots_[bots_.size() - 1]; 
  bots_.pop_back();

  bot->setBotManager(nullptr);

  return bot;
}

/**
* Delete a bot of the BotManager.
*
* @param Bot* bot Bot to remove.
*/
gsl::owner<Bot*> VectorBotManager::removeBot(Bot* bot) 
{
  gsl::owner<Bot*> removed = nullptr;
  auto it = std::find(std::begin(bots_), std::end(bots_), bot);

  if (it != std::end(bots_)) {
    removed = *it;
    bots_.erase(it);
    removed->setBotManager(nullptr);
  }

  return removed;
}

bool VectorBotManager::contains(const Bot* bot) const
{
  auto it = std::find(std::begin(bots_), std::end(bots_), bot);
  return it != std::end(bots_);
}

/**
* Get the game that hold this BotManager.
*
* @return Game*
*/
Game* VectorBotManager::getGame()
{
  return game_;
}

/**
* Get the game that hold this BotManager.
*
* @return const Game*
*/
const Game* VectorBotManager::getGame() const
{
  return game_;
}

/**
* Change the game that hold this BotManager.
*
* @param Game* game
*/
void VectorBotManager::setGame(Game* game) 
{
  if(game != game_) {
    
    if(game_ != nullptr) {
      Game* oldGame = game_;
      game_ = nullptr;
      
      oldGame->setBotManager(nullptr);
    }
    
    game_ = game;
    
    if(game_ != nullptr) {
      gsl::owner<BotManager*> oldManager = game_->setBotManager(this);
      
      if(oldManager != nullptr) {
        delete oldManager;
      }
    }
  }
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
  for(Bot* bot : bots_) {
    bot->nextTurn();
  }
}

