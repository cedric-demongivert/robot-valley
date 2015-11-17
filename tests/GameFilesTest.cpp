#define BOOST_TEST_DYN_LINK
#include "boost/test/unit_test.hpp"
#include "board/BoardLoader.hpp"
#include "game/GameLoader.hpp"
#include "board/FixedBoard.hpp"
#include "game/GameWriter.hpp"
#include "gamse/SimpleGame.hpp"
#include "bot/VectorBotManager.hpp"
#include "bot/SimpleBot.hpp"

#include "GSL/gsl.h"

#include <cstdlib>


gsl::owner<FixedBoard*> ReadFile(){
	return BoardLoader::loadTxtBoard("TEST_init.csv");
}

void WriteToFile(Game* game){
	GameWriter::writeToFile("TEST_maj.csv", game);
}


void createGame(){
	
	gsl::owner<Board*> board= ReadFile();
	
	BotManager* BM = new VectorBotManager();
	gsl::owner<SimpleBot*> bot1 = new SimpleBot();
	gsl::owner<SimpleBot*> bot2 = new SimpleBot();
	
	BM->addBot(bot1);
	BM->addBot(bot2);
	
	
	SimpleGame* game = new SimpleGame(board, BM);
	
	(*bot1)->setLocation(3,3);
	
	
	WriteToFile();
}

BOOST_AUTO_TEST_CASE( GameFilesTest )
{
	createGame();
}
