#include "game/GameLoader.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


gsl::owner<Game*> GameLoader::loadTxtBoard(const std::string& filename){
	
	
	std::ifstream infile(filename.c_str());

	
	std::string line;
	int nbLines=0, nbColumns=0;
	
	std::vector<TileInterface*> tabTile;
	BotManager* botM = new VectorBotManager();

	int nbTurn = 20; // Number of turn for the game

	/* initialize random seed: */
	srand(time(NULL));
	
	while (std::getline(infile, line)){
			
		nbColumns = 0;

		std::stringstream ss(line);
		std::string tileDesc;
		
		char delim = ';';
		
		while (std::getline(ss, tileDesc, delim)) {
			
			TileInterface* created = nullptr;

			if (tileDesc == "#") {
				created = new WallTile();
			}
			else if (tileDesc == "F") {
				created = new FactoryTile();
			}
			else if (tileDesc == ".") {
				created = new Tile();
			}
			else if (tileDesc == "B") {
				created = new Tile();
				Bot* bot = new StupidBot(nbColumns, nbLines);
				botM->addBot(bot);
			}
			else if (tileDesc == "AB") {
				created = new Tile();
				AutoBot* bot = new AutoBot(nbColumns, nbLines);
				bot->setInstructions("./data/instructions/instructions.txt");
				botM->addBot(bot);
			}
			else if (tileDesc == "RB") {
				created = new Tile();
				AutoBot* bot = new AutoBot(nbColumns, nbLines);
				bot->setInstructions(nbTurn);
				botM->addBot(bot);
			}
			else {
				created = new Tile();
			}
			
			created->setLocation(nbColumns, nbLines );
			tabTile.push_back(created);


			nbColumns++;
		}
		nbLines++;
	}

	infile.close();
	
	gsl::owner<Board*> fb= new FixedBoard(nbColumns, nbLines);
	for (TileInterface* tile : tabTile) {
		tile->setBoard(fb);
	}

	Game* sg = new SimpleGame(fb, botM);
	sg->setNbturn(nbTurn);

	return sg;
}
