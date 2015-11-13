#include "game/SimpleGame.hpp"

/**
 * @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
 */

/**
* Create a simple preconfigured game.
*/
SimpleGame::SimpleGame()
 : board_(gsl::owner<Board*> (new FixedBoard(25, 25))),
   botManager_(gsl::owner<BotManager*> (new VectorBotManager()))
{ }
    
/**
 * Create a simple game with a specific board.
 * 
 * @param gsl::owner<Board*> board
 */
SimpleGame::SimpleGame(gsl::owner<Board*> board)
 : board_(board),
   botManager_(gsl::owner<BotManager*> (new VectorBotManager()))
{ }

/**
 * Create a custom configured simple game.
 * 
 * @param gsl::owner<Board*> board
 * @param gsl::owner<BotManager*> bots
 */
SimpleGame::SimpleGame(gsl::owner<Board*> board, gsl::owner<BotManager*> bots)
 : board_(board),
   botManager_(bots)
{ }
    
/**
 * Create a copy of another game.
 * 
 * @param const Game& toCopy
 */
SimpleGame::SimpleGame(const Game& toCopy)
 : board_(toCopy.getBoard()->copy()),
   botManager_(toCopy.getBotManager()->copy())
{}
    
/**
 * Destructor.
 */
SimpleGame::~SimpleGame()
{
  delete board_;
  board_ = nullptr;
  delete botManager_;
  botManager_ = nullptr;
}

/**
 * Return the BotManager.
 * 
 * @return BotManager*
 */
BotManager* SimpleGame::getBotManager()
{
  return botManager_;
}

/**
 * Return the BotManager.
 * 
 * @return const BotManager*
 */
const BotManager* SimpleGame::getBotManager() const
{
  return botManager_;
}

/**
 * Change the BotManager.
 * 
 * The old BotManager will be destroyed.
 * 
 * @param gsl::owner<BotManager*> newManager
 */
void SimpleGame::setBotManager(gsl::owner<BotManager*> newManager)
{
  if(botManager_ != nullptr) {
    delete botManager_;
    botManager_ = nullptr;
  }
  
  botManager_ = newManager;
}

/**
 * Return the board.
 * 
 * @return Board*
 */
Board* SimpleGame::getBoard()
{
  return board_;
}

/**
 * Return the board.
 * 
 * @return const Board*
 */
const Board* SimpleGame::getBoard() const
{
  return board_;
}

/**
 * Change the GameBoard.
 * 
 * The old board will be destroyed.
 * 
 * @param gsl::owner<Board*> newBoard
 */
void SimpleGame::setBoard(gsl::owner<Board*> newBoard)
{
  if(board_ != nullptr) {
    delete board_;
    board_ = nullptr;
  }
  
  board_ = newBoard;
}

/**
 * Pass a turn.
 */
void SimpleGame::nextTurn()
{
  if(board_ != nullptr) board_->nextTurn();
  if(botManager_ != nullptr) botManager_->nextTurn();
}
