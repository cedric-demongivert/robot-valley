#include "WallTile.hpp"

/**
*  @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*
*  A wall.
*/

WallTile::WallTile() : Tile() {};
WallTile::WallTile(Board* board) : Tile(board) {};
WallTile::WallTile(const TileInterface& toCopy) : Tile(toCopy) {};
WallTile::WallTile(const TileInterface& toCopy, Board* board) : Tile(toCopy, board) {};
WallTile::WallTile(const TileInterface& toCopy, Board* board, const int x, const int y) : Tile(toCopy, board, x, y) {};

WallTile::~WallTile()
{ }

bool WallTile::accept(const Bot& bot) const
{
  return false;
}

void WallTile::onEnter(Bot& bot)
{
  
}

void WallTile::onExit(Bot& bot)
{
  
}

gsl::owner<TileInterface*> WallTile::copy() const
{
  return new WallTile(*this);
}

int WallTile::getID() const
{
  return WALL_TILE_ID;
}

