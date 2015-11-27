#ifndef __GAMELOADER_HPP
#define __GAMELOADER_HPP

#include "game/Game.hpp"
#include "board/FixedBoard.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "tile/Tile.hpp"
#include "tile/WallTile.hpp"
#include "tile/FactoryTile.hpp"
#include "bot/VectorBotManager.hpp"
#include "bot/StupidBot.hpp"
#include "bot/AutoBot.hpp"
#include "game/SimpleGame.hpp"

#include <stdio.h>
#include <string.h>
#include "GSL/gsl.h"


/**
 *	@author K/OURIO Alexandre <kourio.alexandre@gmail.com>
 *
 * 	A static class that loads a game from a file.
 */
class GameLoader{
  public:

	  /**
	   *	Return a game created with settings within the file given.
	   *
	   * 	@param const std::string& filename - the path to the setting file of a board.
	   *
	   * 	@return	gsl::owner<Board*> - the created board.
	   *
	   * 	@throws std::ios_base::failure - if no existing file match this filename. 
	   * 	@throws BoardLoadingErrorException - if the board couldn't be load correctly.
	   */
	  static gsl::owner<Game*> loadTxtBoard(const std::string& filename);
};



#endif
