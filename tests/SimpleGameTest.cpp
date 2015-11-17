#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "game/SimpleGame.hpp"
#include "board/FixedBoard.hpp"
#include "bot/VectorBotManager.hpp"

/**
* Test case of SimpleGame class.
*/
BOOST_AUTO_TEST_CASE(SimpleGameTest)
{
  SimpleGame* game = new SimpleGame();

  Board* firstBoard = new FixedBoard(2, 2);
  Board* secondBoard = new FixedBoard(2, 2);
  Board* oldBoard = nullptr;

  BotManager* firstManager = new VectorBotManager();
  BotManager* secondManager = new VectorBotManager();
  BotManager* oldBotManager = nullptr;

  // Initial values test
  BOOST_REQUIRE(game->getBoard() == nullptr);
  BOOST_REQUIRE(game->getBotManager() == nullptr);

  // First set test
  oldBoard = game->setBoard(firstBoard);
  oldBotManager = game->setBotManager(firstManager);

  BOOST_REQUIRE(oldBoard == nullptr);
  BOOST_REQUIRE(oldBotManager == nullptr);

  BOOST_REQUIRE(game->getBoard() == firstBoard);
  BOOST_REQUIRE(game->getBotManager() == firstManager);

  BOOST_REQUIRE(firstBoard->getGame() == game);
  BOOST_REQUIRE(firstManager->getGame() == game);

  // Second set test
  oldBoard = game->setBoard(secondBoard);
  oldBotManager = game->setBotManager(secondManager);

  BOOST_REQUIRE(oldBoard == firstBoard);
  BOOST_REQUIRE(oldBotManager == firstManager);

  BOOST_REQUIRE(game->getBoard() == secondBoard);
  BOOST_REQUIRE(game->getBotManager() == secondManager);

  BOOST_REQUIRE(firstBoard->getGame() == nullptr);
  BOOST_REQUIRE(firstManager->getGame() == nullptr);

  BOOST_REQUIRE(secondBoard->getGame() == game);
  BOOST_REQUIRE(secondManager->getGame() == game);

  // Unregister test
  game->setBoard(nullptr);
  game->setBotManager(nullptr);

  BOOST_REQUIRE(secondBoard->getGame() == nullptr);
  BOOST_REQUIRE(secondManager->getGame() == nullptr);

  delete game;
  delete firstBoard;
  delete secondBoard;
  delete firstManager;
  delete secondManager;
}
