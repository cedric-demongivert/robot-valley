#define BOOST_TEST_DYN_LINK
#include "boost/test/unit_test.hpp"
#include "Tile.hpp"
#include <cstdlib>


class Bot;
class Board;

void TileCreationTest(){
	
	
	Board myBoard(50,50); 
	Bot mybot();
	
	
	Tile myTile(&myBoard);
	
	
	BOOST_TEST( myTile.getBoard() == &myBoard);
	BOOST_TEST( myTile.getBot() == nullptr);
	BOOST_TEST( myTile.isFree() == true);
	
	myTile.onEnter(&mybot);
	BOOST_TEST( myTile.isFree() == false);
	BOOST_TEST( myTile.getBot() == &mybot);
	
	
	myTile.onExit(mybot);
	BOOST_TEST( myTile.isFree() == true);
	
	
	delete(myTile);
	BOOST_TEST( myTile == nullptr);
}

BOOST_AUTO_TEST_CASE( TileTest )
{
	TileCreationTest();
}
