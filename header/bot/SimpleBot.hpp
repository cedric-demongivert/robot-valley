#ifndef __SIMPLE_BOT_HPP
#define __SIMPLE_BOT_HPP

#include "bot/Bot.hpp"
#include "TileInterface.hpp"
#include "GSL/gsl.h"
#include <cstdlib>

/**
 * @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
 *
 * A basic implementation of the Bot interface.
 * 
 * @class SimpleBot
 */
class SimpleBot
  : public Bot
{
  public:
    /**
     * Create a simple bot.
     */
    SimpleBot();
    
    /**
     * Create a simple bot with a specific position.
     * 
     * @param const std::size_t x
     * @param const std::size_t y
     */
    SimpleBot(const std::size_t x, const std::size_t y);
    
    /**
     * Create a bot on a tile.
     * 
     * @param TileInterface* tile
     */
    SimpleBot(const gsl::not_null<TileInterface*> tile);
    
    /**
     * Copy a generic bot.
     * 
     * @param const Bot* toCopy
     */
    SimpleBot(const Bot* toCopy);
    
    /**
     * Bot destructor.
     */
    virtual ~SimpleBot();
    
    /**
     * Return the x coordinate of that bot on a board.
     * 
     * @return std::size_t x
     */
    std::size_t getX() const;
    
    /**
     * Return the y coordinate of that bot on a board.
     * 
     * @return std::size_t y
     */
    std::size_t getY() const;
    
    /**
     * Change the location of that bot on the board.
     * 
     * Call that function only if you are a kind of BotManager.
     * 
     * @param const std::size_t x New x coordinate of the bot.
     * @param const std::size_t y New y coordinate of the bot.
     * 
     * @return void
     */
    virtual void setLocation(
      const std::size_t x,
      const std::size_t y
    );
    
    /**
     * Get the tile under the bot.
     * 
     * @return TileInterface*
     */
    TileInterface* getTile();
    const TileInterface* getTile() const;
    
    /**
     * Change the tile under the bot.
     * 
     * @param TileInterface* const newTile
     * 
     * @return void
     */
    virtual void setTile(TileInterface* const newTile);
    
  protected:
    std::size_t x_;
    std::size_t y_;
    TileInterface* tile_;
};

#endif
