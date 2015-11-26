#ifndef __SCALLOP_GAME_VIEWER_HPP
#define __SCALLOP_GAME_VIEWER_HPP

#include "game/Game.hpp"
#include "scallop/SDLScallopShell.hpp"
#include "GSL/gsl.h"
#include "tile/Tile.hpp"
#include "tile/WallTile.hpp"
#include "tile/FactoryTile.hpp"

/**
* @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*
* Permet de visualiser une partie standard.
*
* @class ScallopGameViewer
*/
class ScallopGameViewer
{
  public:
    ScallopGameViewer(gsl::not_null<Game*> game_);

    virtual ~ScallopGameViewer();

    virtual void run();

  protected:
    Game* game_;
    SDLScallopShell* shell_;

    char getTileChar(const TileInterface& tile) const;
    void printBoard();
    void printBots();
};

#endif