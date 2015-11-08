#include "BoardLoader.hpp"
#include <fstream>
#include <sstream>
#include <string>

Board* BoardLoader::loadTxtBoard(const std::string& filename)
{
	
	std::ifstream infile(filename.c_str());
	//~ if(!infile)
		//~ throw NoFileException
		
	std::string line;
	while (std::getline(infile, line)){
		
	}

  return nullptr;
}
