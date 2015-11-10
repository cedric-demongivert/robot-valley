#include "board/BoardLoader.hpp"
#include "board/FixedBoard.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>




static gsl::owner<Board*> BoardLoader::LoadTxtBoard(String filename){
	
	
	std::ifstream infile(filename.c_str());
	infile.exceptions ( ifstream::failbit );

	
	std::string line;
	int nbLines=0, nbColumns=0;
	

	while (std::getline(infile, line)){
		
		nbLines++;
		bColumns=0;
				
		std::stringstream ss(line);
		std::string tileDesc;
		char delim = ';';
		
		while (std::getline(ss, tileDesc, delim)) {
			nbColumns++;
		}
		
	}


	infile.close();
	
	
	gsl::owner<Board*> fb (new FixedBoard(nbColumns, nbLines));
	
	return fb;
}
