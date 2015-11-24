#include "game/SimpleGame.hpp"
#include "board/FixedBoard.hpp"
#include "scallop/SDLScallopShell.hpp"
#include "Tile.hpp"
#include "WallTile.hpp"
#include "bot/VectorBotManager.hpp"
#include "viewer/ScallopGameViewer.hpp"
#include "SDL.h"
#include "bot/SimpleBot.hpp"
#include "bot/StupidBot.hpp"

#define VERSION 0.1
#define TITLE "Robot Valley v0.1"

int main(int argc, char *argv[])
{
  SimpleGame game;

  FixedBoard* map = new FixedBoard(20, 20);
  for (int i = 0; i < 20; ++i) {
    for (int j = 0; j < 20; ++j) {
      if (i == 0 || j == 0 || i == 19 || j == 19 || (i == 10 && j == 10)) {
        map->setTile(i, j, new WallTile());
      }
      else {
        map->setTile(i, j, new Tile());
      }
    }
  }
      
  game.setBoard(map);

  VectorBotManager* manager = new VectorBotManager();
  manager->addBot(new SimpleBot(2,2));
  manager->addBot(new StupidBot(10, 2));

  game.setBotManager(manager);

  ScallopGameViewer viewer (&game);
  viewer.run();

  return EXIT_SUCCESS;
}
