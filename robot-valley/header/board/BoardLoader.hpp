#ifndef __BOARDLOADER_HPP
#define __BOARDLOADER_HPP

#include "board/Board.hpp"
#include <stdio.h>
#include <string.h>
#include "GSL/gsl.h"


/**
 *	@author K/OURIO Alexandre <kourio.alexandre@gmail.com>
 *
 * 	A static class that loads a board from a file.
 */
class BoardLoader{
  public:

	  /**
	   *	Return a board created with settings within the file given.
	   *
	   * 	@param const std::string& filename - the path to the setting file of a board.
	   *
	   * 	@return	gsl::owner<Board*> - the created board.
	   *
	   * 	@throws std::ios_base::failure - if no existing file match this filename. 
	   * 	@throws BoardLoadingErrorException - if the board couldn't be load correctly.
	   */
	  static gsl::owner<Board*> loadTxtBoard(const std::string& filename);
};



#endif
