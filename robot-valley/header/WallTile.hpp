#ifndef __WALL_TILE_HPP
#define __WALL_TILE_HPP

#include "Tile.hpp"

#define WALL_TILE_ID 1


/**
 *  @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
 * 
 *  A wall.
 * 
 *  @class WallTile
 */
 
class WallTile : public Tile
{
  public:
    WallTile();
    WallTile(Board* board);
    WallTile(const TileInterface& toCopy);
    WallTile(const TileInterface& toCopy, Board* board);
    WallTile(const TileInterface& toCopy, Board* board, const int x, const int y);

    virtual ~WallTile();

    virtual bool accept(const Bot& bot) const override;
    virtual void onEnter(Bot& bot) override;
    virtual void onExit(Bot& bot) override;

    virtual gsl::owner<TileInterface*> copy() const override;

    virtual int getID() const override;
};

#endif
