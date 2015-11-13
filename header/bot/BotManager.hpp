#ifndef __BOT_MANAGER_HPP
#define __BOT_MANAGER_HPP

#include <iterator>
#include "bot/Bot.hpp"
#include "GSL/gsl.hpp"
#include "mixins/Copiable.hpp"


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
  : public Copiable<BotManager*>
{
  public:
    /**
     * Destructor.
     */
    virtual ~BotManager()
    { };
    
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
     */
    virtual void removeBot(const std::size_t index) = 0;
    
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
    virtual gsl::owner<BotManager*> copy() const = 0;
    
    /**
     * Pass a turn.
     */
    virtual void nextTurn() = 0;
}

#endif
