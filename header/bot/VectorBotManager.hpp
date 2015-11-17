#ifndef __VECTOR_BOT_MANAGER_HPP
#define __VECTOR_BOT_MANAGER_HPP

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
    virtual ~VectorBotManager();
    
    /**
     * Return a bot of the BotManager.
     * 
     * @throw std::out_of_range If index is out of range.
     * 
     * @param const std::size_t index
     * 
     * @return Bot*
     */
    Bot* getBot(const std::size_t index) override;
    
    /**
     * Return a bot of the BotManager.
     * 
     * @throw std::out_of_range If index is out of range.
     * 
     * @param const std::size_t index
     * 
     * @return const Bot*
     */
    const Bot* getBot(const std::size_t index) const override;
  
    /**
     * Return the bot count.
     * 
     * @return std::size_t
     */
    std::size_t size() const override;
    
    /**
     * Add a bot to the manager.
     * 
     * @param gsm::owner<Bot*> bot
     */
    void addBot(gsl::owner<Bot*> bot) override;
    
    /**
     * Delete a bot of the BotManager.
     * 
     * @throw std::out_of_range If index is out of range.
     * 
     * @param const std::size_t index
     */
    gsl::owner<Bot*> removeBot(const std::size_t index) override;

    /**
    * Delete a bot of the BotManager.
    *
    * @param Bot* bot Bot to remove.
    */
    gsl::owner<Bot*> removeBot(Bot* bot) override;
    
    /**
     * Return an iterator at the begining of the bot collection.
     * 
     * @return BotIterator
     */
    BotIterator begin() override;
    
    /**
     * Return an iterator at the begining of the bot collection.
     * 
     * @return ConstBotIterator
     */
    ConstBotIterator begin() const override;
    
    /**
     * Return an iterator at the end of the bot collection.
     * 
     * @return BotIterator
     */
    BotIterator end() override;
    
    /**
     * Return an iterator at the end of the bot collection.
     * 
     * @return ConstBotIterator
     */
    ConstBotIterator end() const override;
    
    /**
    * Return true if this manager already contains that bot.
    *
    * @param const Bot* bot Bot to test.
    *
    * @return bool True if this manager already hold that bot.
    */
    virtual bool contains(const Bot* bot) const override;

    /**
     * Return a deep-copy of this manager.
     * 
     * @return gsl::owner<BotManager*>
     */
    virtual gsl::owner<BotManager*> copy() const override;
    
    /**
     * Pass a turn.
     */
    virtual void nextTurn() override;

    /**
    * Get the game that hold this BotManager.
    *
    * @return Game*
    */
    Game* getGame() override;

    /**
    * Get the game that hold this BotManager.
    *
    * @return const Game*
    */
    const Game* getGame() const override;
    
    /**
    * Change the game that hold this BotManager.
    *
    * @param Game* game
    */
    void setGame(Game* game) override;
    
  protected:
    std::vector<gsl::owner<Bot*>> bots_;
    Game* game_;
};

#endif
