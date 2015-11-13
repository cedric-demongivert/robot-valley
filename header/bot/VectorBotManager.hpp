#ifndef __VECTOR_BOT_MANAGER_HPP
#define __VECTOR_BOT_MANAGER_HPP

#include <iterator>
#include <vector>
#include "bot/BotManager.hpp"

/**
 * @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
 * 
 * An object that store and manage bots.
 * 
 * @class BotManager
 */
class VectorBotManager 
  : public BotManager
{
  public:
  
    /**
     * Create an empty BotManager.
     */
    VectorBotManager();
    
    /**
     * Create a deep-copy of an existing BotManager.
     * 
     * @param const BotManager& manager
     */
    VectorBotManager(const BotManager& manager);
  
    /**
     * Destructor.
     */
    virtual ~VectorBotManager()
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
    Bot* getBot(const std::size_t index);
    
    /**
     * Return a bot of the BotManager.
     * 
     * @throw std::out_of_range If index is out of range.
     * 
     * @param const std::size_t index
     * 
     * @return const Bot*
     */
    const Bot* getBot(const std::size_t index) const;
  
    /**
     * Return the bot count.
     * 
     * @return std::size_t
     */
    std::size_t size() const;
    
    /**
     * Add a bot to the manager.
     * 
     * @param gsm::owner<Bot*> bot
     */
    void addBot(gsl::owner<Bot*> bot);
    
    /**
     * Delete a bot of the BotManager.
     * 
     * @throw std::out_of_range If index is out of range.
     * 
     * @param const std::size_t index
     */
    void removeBot(const std::size_t index);
    
    /**
     * Return an iterator at the begining of the bot collection.
     * 
     * @return BotIterator
     */
    BotIterator begin();
    
    /**
     * Return an iterator at the begining of the bot collection.
     * 
     * @return ConstBotIterator
     */
    ConstBotIterator begin() const;
    
    /**
     * Return an iterator at the end of the bot collection.
     * 
     * @return BotIterator
     */
    BotIterator end();
    
    /**
     * Return an iterator at the end of the bot collection.
     * 
     * @return ConstBotIterator
     */
    ConstBotIterator end() const;
    
    /**
     * Return a deep-copy of this manager.
     * 
     * @return gsl::owner<BotManager*>
     */
    virtual gsl::owner<BotManager*> copy() const;
    
    /**
     * Pass a turn.
     */
    virtual void nextTurn();
    
  protected:
    std::vector<gsl::owner<Bot*>> bots_;
}

#endif
