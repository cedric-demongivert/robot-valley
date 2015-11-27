#ifndef __FACTORY_TILE_HPP
#define __FACTORY_TILE_HPP

#include "tile/Tile.hpp"
#include "bot/AutoBot.hpp"
#include "bot/BotManager.hpp"

#define FACTORY_TILE_ID 2


/**
 *  @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
 * 
 *  A wall.
 * 
 *  @class FactoryTile
 */
 
class FactoryTile : public Tile
{
  public:
	FactoryTile();
	FactoryTile(Board* board);
	FactoryTile(const TileInterface& toCopy);
	FactoryTile(const TileInterface& toCopy, Board* board);
	FactoryTile(const TileInterface& toCopy, Board* board, const int x, const int y);

    virtual ~FactoryTile();

    virtual bool accept(const Bot& bot) const override;
    virtual void onEnter(Bot& bot) override;
    virtual void onExit(Bot& bot) override;

    virtual gsl::owner<TileInterface*> copy() const override;

    virtual int getID() const override;

	virtual void nextTurn() override;


private:
	int nbTurn_create;
	int init_nbTurnToCreate = 5;
};

#endif
