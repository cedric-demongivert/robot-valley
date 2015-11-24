#ifndef __BOT_HPP
#define __BOT_HPP

#include <cstdlib>
#include "TileInterface.hpp"
#include "bot/BotManager.hpp"

#include "mixins/Copiable.hpp"
#include "mixins/Localizable2D.hpp"
#include "mixins/Movable2D.hpp"

/**
* Circular inclusion
*/
class BotManager;

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
    virtual int getX() const override = 0;
    
    /**
     * Return the y coordinate of that bot in the world.
     * 
     * @return int y
     */
    virtual int getY() const override = 0;
   
    /**
    * Change the location of that bot on the board.
    *
    * @param const int x New x coordinate of the bot.
    *
    * @return void
    */
    virtual void setX(const int x) override = 0;

    /**
    * Change the location of that bot on the board.
    *
    * @param const int y New y coordinate of the bot.
    *
    * @return void
    */
    virtual void setY(const int y) override = 0;

    /**
    * Change the location of the object to a defined position.
    *
    * @param const int x
    * @param const int y
    */
    virtual void setLocation(const int x, const int y) override = 0;
    
    /**
    * Return the BotManager that manage this robot.
    *
    * @return BotManager*
    */
    virtual BotManager* getBotManager() = 0;

    /**
    * Return the BotManager that manage this robot.
    *
    * @return const BotManager*
    */
    virtual const BotManager* getBotManager() const = 0;

    /**
    * Change the BotManager that manage this robot
    *
    * @param BotManager* botManager New robot manager.
    */
    virtual void setBotManager(BotManager* botManager) = 0;

    /**
     * Get the tile under the bot.
     * 
     * @return TileInterface*
     */
    virtual TileInterface* getTile() = 0;

    /**
    * Get the tile under the bot.
    *
    * @return const TileInterface*
    */
    virtual const TileInterface* getTile() const = 0;
    
    /**
     * Allocate a copy of that bot.
     * 
     * @return gsl::owner<Bot*> 
     */
    virtual gsl::owner<Bot*> copy() const override = 0;
    
    /**
     * Pass a turn.
     */
    virtual void nextTurn() = 0;
};

#endif
