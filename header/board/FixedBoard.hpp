#ifndef __FIXED_BOARD_HPP
#define __FIXED_BOARD_HPP

#include <cstdlib>
#include <stdexcept>
#include "board/Board.hpp"
#include "utils/HorizontalLinearizer2D.hpp"

/**
* @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*
* A basic constant implementation of Board that use a linear Array
* for storing tiles.
*
* @class FixedBoard
*/
class FixedBoard : public Board
{
  public:
    /**
    * Create a simple empty board.
    *
    * @param const size_t width
    * @param const size_t height
    */
    FixedBoard(const size_t width, const size_t height);

    /**
    * Create a simple empty board with location.
    *
    * @param const size_t width
    * @param const size_t height
    * @param const int x
    * @param const int y
    */
    FixedBoard(const size_t width, const size_t height, const int x, const int y);

    /**
    * Create a simple empty board with a specific storing way.
    *
    * @param const size_t width
    * @param const size_t height
    * @param gsl::owner<Linearizer2D*> linearizer
    */
    FixedBoard(
      const size_t width,
      const size_t height,
      gsl::owner<Linearizer2D*> linearizer
    );

    /**
    * Create a simple empty board with a specific storing way and a location.
    *
    * @param const size_t width
    * @param const size_t height
    * @param const int x
    * @param const int y
    * @param gsl::owner<Linearizer2D*> linearizer
    */
    FixedBoard(
      const size_t width,
      const size_t height,
      const int x, 
      const int y,
      gsl::owner<Linearizer2D*> linearizer
    );

    /**
    * Copy an existing board (deep-copy).
    *
    * @param const BoardInterface& toCopy
    */
    FixedBoard(const Board& toCopy);

    /**
    * Board destructor.
    */
    virtual ~FixedBoard() override;

    /**
    * Return the board height
    *
    * @return std::size_t
    */
    std::size_t getHeight() const override;

    /**
    * Return the board width.
    *
    * @return std::size_t
    */
    std::size_t getWidth() const override;

    /**
    * Return the x coordinate of the first tile in that board.
    *
    * @return int
    */
    int getX() const override;

    /**
    * Return the y coordinate of the first tile in that board.
    *
    * @return int
    */
    int getY() const override;

    /**
    * Return a begin iterator over this board.
    *
    * @return BoardIterator
    */
    BoardIterator begin() override;
    
    /**
    * Return a begin iterator over this board.
    *
    * @return ConstBoardIterator
    */
    ConstBoardIterator begin() const override;

    /**
    * Return an end iterator over this board.
    *
    * @return BoardIterator
    */
    BoardIterator end() override;
    
    /**
    * Return an end iterator over this board.
    *
    * @return ConstBoardIterator
    */
    ConstBoardIterator end() const override;

    /**
    * Return a tile at a specific location.
    *
    * @param const int x
    * @param const int y
    *
    * @throws std::out_of_range If the location (x,y) do not exist.
    *
    * @return TileInterface* Tile at the (x,y) location, while return nullptr if
    *                        the tile do not exist.
    */
    virtual TileInterface* getTile(
      const int x,
      const int y
    ) override;

    /**
    * Return a tile at a specific location.
    *
    * @param const int x
    * @param const int y
    *
    * @throws std::out_of_range If the location (x,y) do not exist.
    *
    * @return const TileInterface* Tile at the (x,y) location, while return nullptr if
    *                        the tile do not exist.
    */
    virtual const TileInterface* getTile(
      const int x,
      const int y
    ) const override;

    /**
    * Set a tile in a specific location.
    *
    * If a tile already exist at the location, this object will destroy it.
    *
    * @param const int x
    * @param const int y
    * @param gsl::owner<TileInterface*> tile Tile to set.
    *
    * @throws std::out_of_range If the location (x,y) do not exist.
    *
    * @return void
    */
    virtual void setTile(
      const int x,
      const int y,
      gsl::owner<TileInterface*> tile
    ) override;

    /**
    * Copy a tile in a specific location.
    *
    * If a tile already exist at the location, the board will destroy it.
    *
    * @param const int x
    * @param const int y
    * @param const TileInterface& tile Tile to set.
    *
    * @throws std::out_of_range If the location (x,y) do not exist.
    *
    * @return void
    */
    virtual void setTile(
      const int x,
      const int y,
      const TileInterface& tile
    ) override;
    
    /**
     * Return the Game that use that board.
     * 
     * @return Game* game
     */
    Game* getGame() override;
    
    /**
     * Return the Game that use that board.
     * 
     * @return const Game* game
     */
    const Game* getGame() const override;
    
    /**
     * Change the Game that use that board.
     * 
     * @return Game* game
     */
    void setGame(Game* game) override;

    /**
    * Check if a location is in the board.
    *
    * @param const int x
    * @param const int y
    *
    * @return bool True if the (x,y) location is in the board.
    */
    virtual bool contains(
      const int x,
      const int y
    ) const override;
    
    /**
     * Pass a turn.
     */
    virtual void nextTurn() override;
    
    /**
     * Allocate a new copy of this board.
     */
    virtual gsl::owner<Board*> copy() const override; 
  protected:
    gsl::owner<TileInterface*>* tiles_;
    gsl::owner<Linearizer2D*> linearizer_;
    Game* game_;
};

#endif
