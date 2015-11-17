#ifndef __BOT_MANAGER_HPP
#define __BOT_MANAGER_HPP

#include <iterator>
#include "bot/Bot.hpp"
#include "GSL/gsl.h"
#include "mixins/Copiable.hpp"
#include "game/Game.hpp"

/**
* Circular inclusion
*/
class Bot;
class Game;

typedef std::iterator<std::input_iterator_tag, Bot*> 
        BotIterator;
        
typedef std::iterator<std::input_iterator_tag, const Bot*> 
        ConstBotIterator;

/**
 * @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
 * 
 * An object that store and manage bots.
 * 
 * @class BotManager
 */
class BotManager 
  : public Copiable<BotManager>
{
  public:
    /**
     * Destructor.
     */
    virtual ~BotManager() { };
    
    /**
     * Return a bot of the BotManager.
     * 
     * @throw std::out_of_range If index is out of range.
     * 
     * @param const std::size_t index
     * 
     * @return Bot*
     */
    virtual Bot* getBot(const std::size_t index) = 0;
    
    /**
     * Return a bot of the BotManager.
     * 
     * @throw std::out_of_range If index is out of range.
     * 
     * @param const std::size_t index
     * 
     * @return const Bot*
     */
    virtual const Bot* getBot(const std::size_t index) const = 0;
  
    /**
     * Return the bot count.
     * 
     * @return std::size_t
     */
    virtual std::size_t size() const = 0;
    
    /**
     * Add a bot to the manager.
     * 
     * @param gsm::owner<Bot*> bot
     */
    virtual void addBot(gsl::owner<Bot*> bot) = 0;
    
    /**
     * Delete a bot of the BotManager.
     * 
     * @throw std::out_of_range If index is out of range.
     * 
     * @param const std::size_t index
     *
     * @return gsl::owner<Bot*> The removed bot, if a bot was removed.
     */
    virtual gsl::owner<Bot*> removeBot(const std::size_t index) = 0;

    /**
    * Delete a bot of the BotManager.
    *
    * @param Bot* bot Bot to remove.
    *
    * @return gsl::owner<Bot*> The removed bot, if a bot was removed.
    */
    virtual gsl::owner<Bot*> removeBot(Bot* bot) = 0;
    
    /**
    * Return true if this manager already contains that bot.
    *
    * @param const Bot* bot Bot to test.
    *
    * @return bool True if this manager already hold that bot.
    */
    virtual bool contains(const Bot* bot) const = 0;

    /**
     * Return an iterator at the begining of the bot collection.
     * 
     * @return BotIterator
     */
    virtual BotIterator begin() = 0;
    
    /**
     * Return an iterator at the begining of the bot collection.
     * 
     * @return ConstBotIterator
     */
    virtual ConstBotIterator begin() const = 0;
    
    /**
     * Return an iterator at the end of the bot collection.
     * 
     * @return BotIterator
     */
    virtual BotIterator end() = 0;

    /**
    * Get the game that hold this BotManager.
    *
    * @return Game*
    */
    virtual Game* getGame() = 0;

    /**
    * Get the game that hold this BotManager.
    *
    * @return const Game*
    */
    virtual const Game* getGame() const = 0;
    
    /**
    * Change the game that hold this BotManager.
    *
    * @param Game* game
    */
    virtual void setGame(Game* game) = 0;
    
    /**
     * Return an iterator at the end of the bot collection.
     * 
     * @return ConstBotIterator
     */
    virtual ConstBotIterator end() const = 0;
    
    /**
     * Return a deep-copy of this manager.
     * 
     * @return gsl::owner<BotManager*>
     */
    virtual gsl::owner<BotManager*> copy() const override = 0;
    
    /**
     * Pass a turn.
     */
    virtual void nextTurn() = 0;
};

#endif
