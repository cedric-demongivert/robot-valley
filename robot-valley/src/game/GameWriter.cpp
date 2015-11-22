#include "game/GameWriter.hpp"
#include "bot/BotManager.hpp"
#include "board/Board.hpp"
#include "board/BoardIterator.hpp"
#include "Tile.hpp"
#include <fstream>
#include <iostream>


void GameWriter::writeToFile(const std::string& filename, const Game& game){
	
	
	// Create file
	std::ofstream myfile;
	myfile.open (filename);
	myfile << "Writing this to a file.\n";
	
	
	// Writes all Tiles
	const Board* board= game.getBoard();

	int indice=0;
	for(auto board_it= board->begin(); board_it!=board->end(); board_it++){
		const TileInterface* T = (*board_it);
		
		if(T->isFree())
			myfile << "T;";
		else
			myfile << "TB;";
			
			
		// Check if this Tile is the end of a line
		if( indice == board->getWidth())
		{
			myfile << std::endl;
			indice=0;
		}
		else
			indice++;
	}
	
	
	// Close the file
	myfile.close();
}
