#include "BoardLoader.hpp"
#include <fstream>
#include <sstream>
#include <string>


static Board* BoardLoader::LoadTxtBoard(String filename){
	
	
	std::ifstream infile(filename.c_str());
	//~ if(!infile)
		//~ throw NoFileException
		
	std::string line;
	while (std::getline(infile, line)){
		
	}
}
