#include "game/SimpleGame.hpp"
#include "board/FixedBoard.hpp"
#include "scallop/SDLScallopShell.hpp"
#include "bot/VectorBotManager.hpp"
#include "SDL.h"

#define VERSION 0.1
#define TITLE "Robot Valley v0.1"

int main(int argc, char *argv[])
{
  SimpleGame game;

  SDLScallopShell shell(TITLE, 50, 30);

  shell.nextln(">> PRESS SPACE FOR AN EXTRA TURN ! :)");
  shell.render();

  for (size_t x = 0; x < 28; ++x)
  {
    shell.waitEnter();
    shell.setChar(x+1, x+1, 'X');
    shell.render();
  }

  return EXIT_SUCCESS;
}
