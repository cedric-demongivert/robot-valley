#ifndef __BOT_HPP
#define __BOT_HPP

#include <cstdlib>
#include "TileInterface.hpp"

#include "mixins/Copiable.hpp"
#include "mixins/Localizable2D.hpp"
#include "mixins/Movable2D.hpp"

/**
 * @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
 * 
 * A bot that can handle some events, move on the board and act.
 * 
 * @class Bot
 */
class Bot 
  : public Copiable<Bot>,
    public Localizable2D,
    public Movable2D
{
  public:
    /**
     * Bot destructor.
     */
    virtual ~Bot() {};
    
    /**
     * Return the x coordinate of that bot in the world.
     * 
     * @return int x
     */
    virtual int getX() const = 0;
    
    /**
     * Return the y coordinate of that bot in the world.
     * 
     * @return int y
     */
    virtual int getY() const = 0;
    
    /**
     * Change the location of that bot in the world.
     * 
     * @param const std::size_t x New x coordinate of the bot.
     * @param const std::size_t y New y coordinate of the bot.
     * 
     * @return void
     */
    virtual void setLocation(
      const int x,
      const int y
    ) = 0;
    
    /**
     * Change the position of that bot to another localizable object.
     * 
     * @param const Localizable2D& other
     */
    virtual void setLocation(const Localizable2D& other) = 0;
    
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
    
    /**
     * Allocate a copy of that bot.
     * 
     * @return gsl::owner<Bot*> 
     */
    virtual gsl::owner<Bot*> copy() const = 0;
};

#endif
