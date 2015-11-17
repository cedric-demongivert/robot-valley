#ifndef __SIMPLE_GAME_HPP
#define __SIMPLE_GAME_HPP

#include <cstdlib>
#include <iterator>
#include "game/Game.hpp"
#include "board/FixedBoard.hpp"
#include "bot/VectorBotManager.hpp"

/**
 * @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
 * 
 * An implementation of the Game interface.
 * 
 * @class SimpleGame
 */
class SimpleGame
  : public Game
{
  public:
    
    /**
     * Create a simple preconfigured game.
     */
    SimpleGame();
    
    /**
     * Create a simple game with a specific board.
     * 
     * @param gsl::owner<Board*> board
     */
    SimpleGame(gsl::owner<Board*> board);
    
    /**
     * Create a custom configured simple game.
     * 
     * @param gsl::owner<Board*> board
     * @param gsl::owner<BotManager*> bots
     */
    SimpleGame(gsl::owner<Board*> board, gsl::owner<BotManager*> bots);
    
    /**
     * Create a copy of another game.
     * 
     * @param const Game& toCopy
     */
    SimpleGame(const Game& toCopy);
    
    /**
     * Destructor.
     */
    virtual ~SimpleGame() override;
    
    /**
     * Return the BotManager.
     * 
     * @return BotManager*
     */
    BotManager* getBotManager() override;
    
    /**
     * Return the BotManager.
     * 
     * @return const BotManager*
     */
    const BotManager* getBotManager() const override;
    
    /**
     * Change the BotManager.
     * 
     * The old BotManager will be destroyed.
     * 
     * @param gsl::owner<BotManager*> newManager
     * 
     * @return gsl::owner<BotManager*> oldManager
     */
    gsl::owner<BotManager*> setBotManager(gsl::owner<BotManager*> newManager) override;
    
    /**
     * Return the board.
     * 
     * @return Board*
     */
    Board* getBoard() override;
    
    /**
     * Return the board.
     * 
     * @return const Board*
     */
    const Board* getBoard() const override;
    
    /**
     * Change the GameBoard.
     *      * 
     * @param gsl::owner<Board*> newBoard
     * 
     * @return gsl::owner<Board*> The old board.
     */
    gsl::owner<Board*> setBoard(gsl::owner<Board*> newBoard) override;
    
    /**
     * Pass a turn.
     */
    virtual void nextTurn() override;
    
  protected:
    gsl::owner<BotManager*> botManager_;
    gsl::owner<Board*> board_;
}

#endif
