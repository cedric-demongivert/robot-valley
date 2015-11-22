#ifndef __GAMEWRITER_HPP
#define __GAMEWRITER_HPP

#include "board/Board.hpp"
#include <stdio.h>
#include <string.h>
#include "GSL/gsl.h"


/**	
 * 	@author K/OURIO alexandre
 * 
 * 	A static class that writes the actual state of the game on a file.
 */
 
 class GameWriter{
	 public:
	 
		void writeToFile(const std::string& filename, const Game& game);
 };


#endif
