#ifndef __SIMPLE_BOT_HPP
#define __SIMPLE_BOT_HPP

#include "bot/Bot.hpp"
#include "utils/Point2D.hpp"
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
     * @param const int x
     * @param const int y
     */
    SimpleBot(const int x, const int y);
    
    /**
     * Create a simple bot with a specific position.
     * 
     * @param const Localizable2D&
     */
    SimpleBot(const Localizable2D& position);
    
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
    int getX() const;
    
    /**
     * Return the y coordinate of that bot on a board.
     * 
     * @return std::size_t y
     */
    int getY() const;
    
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
    virtual void setLocation(
      const int x,
      const int y
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
    Point2D location_;
    TileInterface* tile_;
};

#endif
