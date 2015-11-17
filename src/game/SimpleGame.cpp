#include "game/SimpleGame.hpp"

/**
 * @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
 */

/**
* Create a simple preconfigured game.
*/
SimpleGame::SimpleGame()
 : board_(nullptr),
   botManager_(nullptr)
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
  if (board_ != nullptr) {
    delete board_;
    board_ = nullptr;
  }

  if (botManager_ != nullptr) {
    delete botManager_;
    botManager_ = nullptr;
  }
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
 * 
 * @return gsl::owner<BotManager*> oldManager
 */
gsl::owner<BotManager*> SimpleGame::setBotManager(gsl::owner<BotManager*> newManager)
{
  gsl::owner<BotManager*> oldManager = nullptr;
  
  if(newManager != botManager_) {
    oldManager = botManager_;
    botManager_ = nullptr;
    
    if(oldManager != nullptr) {
      oldManager->setGame(nullptr);
    }
    
    botManager_ = newManager;
    
    if(botManager_ != nullptr) {
      botManager_->setGame(this);
    }
  }
  
  return oldManager;
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
* @param gsl::owner<Board*> newBoard
* 
* @return gsl::owner<Board*> The old board.
*/
gsl::owner<Board*> SimpleGame::setBoard(gsl::owner<Board*> newBoard)
{
  gsl::owner<Board*> oldBoard = nullptr;
  
  if(newBoard != board_) {
    oldBoard = board_;
    board_ = nullptr;
    
    if(oldBoard != nullptr) {
      oldBoard->setGame(nullptr);
    }
    
    board_ = newBoard;
    
    if(board_ != nullptr) {
      board_->setGame(this);
    }
  }
  
  return oldBoard;
}

/**
 * Pass a turn.
 */
void SimpleGame::nextTurn()
{
  if(board_ != nullptr) board_->nextTurn();
  if(botManager_ != nullptr) botManager_->nextTurn();
}
