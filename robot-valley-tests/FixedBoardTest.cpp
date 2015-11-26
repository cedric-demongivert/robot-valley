#define BOOST_TEST_DYN_LINK
#include "boost/test/unit_test.hpp"
#include "game/SimpleGame.hpp"
#include "board/FixedBoard.hpp"
#include "utils/HorizontalLinearizer2D.hpp"
#include "tile/Tile.hpp"

/**
* Test case of SimpleGame class.
*/
BOOST_AUTO_TEST_CASE(FixedBoardTest)
{
  Game* firstGame = new SimpleGame();
  Game* secondGame = new SimpleGame();

  FixedBoard* board = new FixedBoard(25, 25);
  FixedBoard* secondBoard = new FixedBoard(3, 3);
  HorizontalLinearizer2D linearizer(25, 25);

  // Tile getter / setter test
  for (std::size_t index = 0; index < linearizer.getMaxLinearizedValue(); ++index)
  {
    int x = linearizer.getX(index);
    int y = linearizer.getY(index);
    TileInterface* tile = new Tile();
    board->setTile(x, y, tile);

    BOOST_REQUIRE(board->getTile(x, y) == tile);
    BOOST_REQUIRE(tile->getX() == x);
    BOOST_REQUIRE(tile->getY() == y);
    BOOST_REQUIRE(tile->getBoard() == board);
  }
  
  // Game setter test
  board->setGame(firstGame);
  BOOST_REQUIRE(board->getGame() == firstGame);
  BOOST_REQUIRE(firstGame->getBoard() == board);
  BOOST_REQUIRE(secondGame->getBoard() != board);

  board->setGame(secondGame);
  BOOST_REQUIRE(board->getGame() == secondGame);
  BOOST_REQUIRE(firstGame->getBoard() == nullptr);
  BOOST_REQUIRE(secondGame->getBoard() == board);

  board->setGame(nullptr);
  BOOST_REQUIRE(board->getGame() == nullptr);
  BOOST_REQUIRE(firstGame->getBoard() == nullptr);
  BOOST_REQUIRE(secondGame->getBoard() == nullptr);

  // Tile exchange
  TileInterface* exchanged = board->getTile(5, 10);
  secondBoard->setTile(1, 2, board->getTile(5, 10));

  BOOST_REQUIRE(secondBoard->getTile(1, 2) == exchanged);
  BOOST_REQUIRE(board->getTile(5, 10) == nullptr);
  BOOST_REQUIRE(exchanged->getBoard() == secondBoard);
  BOOST_REQUIRE(exchanged->getX() == 1);
  BOOST_REQUIRE(exchanged->getY() == 2);

  // Destructors
  delete firstGame;
  delete secondGame;
  delete board;
  delete secondBoard;
}
