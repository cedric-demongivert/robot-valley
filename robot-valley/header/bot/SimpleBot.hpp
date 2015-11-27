#ifndef __SIMPLE_BOT_HPP
#define __SIMPLE_BOT_HPP

#include "bot/Bot.hpp"
#include "utils/Point2D.hpp"
#include "tile/TileInterface.hpp"
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
    virtual ~SimpleBot() override;
    
    /**
     * Return the x coordinate of that bot on a board.
     * 
     * @return std::size_t x
     */
    int getX() const override;
    
    /**
     * Return the y coordinate of that bot on a board.
     * 
     * @return std::size_t y
     */
    int getY() const override;

    /**
    * Return the BotManager that manage this robot.
    *
    * @return BotManager*
    */
    virtual BotManager* getBotManager() override;

    /**
    * Return the BotManager that manage this robot.
    *
    * @return const BotManager*
    */
    virtual const BotManager* getBotManager() const override;

    /**
    * Change the BotManager that manage this robot
    *
    * @param BotManager* botManager New robot manager.
    */
    virtual void setBotManager(BotManager* botManager) override;
    
    /**
     * Change the location of that bot on the board.
     * 
     * @param const int x New x coordinate of the bot.
     * 
     * @return void
     */
    virtual void setX(const int x) override;

    /**
    * Change the location of that bot on the board.
    *
    * @param const int y New y coordinate of the bot.
    *
    * @return void
    */
    virtual void setY(const int y) override;

    /**
    * Change the location of the object to a defined position.
    *
    * @param const int x
    * @param const int y
    */
    virtual void setLocation(const int x, const int y) override;
    
    /**
     * Get the tile under the bot.
     * 
     * @return TileInterface*
     */
    TileInterface* getTile() override;

    /**
    * Get the tile under the bot.
    *
    * @return const TileInterface*
    */
    const TileInterface* getTile() const override;
    
    /**
     * Pass a turn.
     */
    virtual void nextTurn() override;

    /**
    * Allocate a copy of that bot.
    *
    * @return gsl::owner<Bot*>
    */
    virtual gsl::owner<Bot*> copy() const override;
    
  protected:
    Point2D location_;
    BotManager* manager_;

    bool canMove(const TileInterface* start, const TileInterface* end) const;
    void doMove(TileInterface* start, TileInterface* end);

    /**
    * Get a tile.
    *
    * @return TileInterface*
    */
    TileInterface* getTile(int x, int y);
};

#endif
