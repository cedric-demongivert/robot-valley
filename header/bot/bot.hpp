#ifndef __BOT_HPP
#define __BOT_HPP

#include <cstdlib>
#include "TileInterface.hpp"

/**
 * @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
 * 
 * A bot that can handle some events, move on the board and act.
 * 
 * @class Bot
 */
class Bot 
{
  public:
    /**
     * Bot destructor.
     */
    virtual ~Bot() {};
    
    /**
     * Return the x coordinate of that bot on a board.
     * 
     * @return std::size_t x
     */
    virtual std::size_t getX() const = 0;
    
    /**
     * Return the y coordinate of that bot on a board.
     * 
     * @return std::size_t y
     */
    virtual std::size_t getY() const = 0;
    
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
    ) = 0;
    
    /**
     * Get the tile under the bot.
     * 
     * @return TileInterface*
     */
    virtual TileInterface* getTile() = 0;
    virtual const TileInterface* getTile() const = 0;
    
    /**
     * Change the tile under the bot.
     * 
     * @param TileInterface* const newTile
     * 
     * @return void
     */
    virtual void setTile(TileInterface* const newTile) = 0;
};

#endif
