#ifndef __BOARDLOADER_HPP
#define __BOARDLOADER_HPP

#include "board/Board.hpp"
#include <stdio.h>
#include <string.h>


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
	 * 	@return	Board* - the created board.
	 *
	 * 	@throws NoFileException - if no existing file match this filename. // Voir common exception, ptete qu'elle existe d�j�
	 * 	@throws BoardLoadingErrorException - if the board couldn't be load correctly.
	 */
	static Board* loadTxtBoard(const std::string& filename);


private:

};



#endif
