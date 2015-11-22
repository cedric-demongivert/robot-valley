#ifndef __GAME_HPP
#define __GAME_HPP

#include "GSL/gsl.h"
#include "board/Board.hpp"
#include "bot/BotManager.hpp"

/**
* Circular inclusion.
*/
class BotManager;

/**
 * @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
 * 
 * A game, with board, bots and turns.
 * 
 * @class Game
 */
class Game 
{
  public:
    /**
     * Destructor
     */
    virtual ~Game()
    { }
  
    /**
     * Return the BotManager.
     * 
     * @return BotManager*
     */
    virtual BotManager* getBotManager() = 0;
    
    /**
     * Return the BotManager.
     * 
     * @return const BotManager*
     */
    virtual const BotManager* getBotManager() const = 0;
    
    /**
     * Change the BotManager.
     * 
     * The old BotManager will be destroyed.
     * 
     * @param gsl::owner<BotManager*> newManager
     * 
     * @return gsl::owner<BotManager*> oldManager
     */
    virtual gsl::owner<BotManager*> setBotManager(gsl::owner<BotManager*> newManager) = 0;
    
    /**
     * Return the board.
     * 
     * @return Board*
     */
    virtual Board* getBoard() = 0;
    
    /**
     * Return the board.
     * 
     * @return const Board*
     */
    virtual const Board* getBoard() const = 0;
    
    /**
     * Change the GameBoard.
     * 
     * @param gsl::owner<Board*> newBoard
     * 
     * @return gsl::owner<Board*> The old board.
     */
    virtual gsl::owner<Board*> setBoard(gsl::owner<Board*> newBoard) = 0;
    
    /**
     * Pass a turn.
     */
    virtual void nextTurn() = 0;
};

#endif
