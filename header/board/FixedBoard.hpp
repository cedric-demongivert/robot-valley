#ifndef __BOARD_HPP
#define __BOARD_HPP

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
    * Copy an existing board (deep-copy).
    *
    * @param const BoardInterface& toCopy
    */
    FixedBoard(const Board& toCopy);

    /**
    * Board destructor.
    */
    virtual ~FixedBoard();

    /**
    * Return the board height
    *
    * @return std::size_t
    */
    std::size_t getHeight() const;

    /**
    * Return the board width.
    *
    * @return std::size_t
    */
    std::size_t getWidth() const;

    /**
    * Return a begin iterator over this board.
    *
    * @return BoardIterator
    */
    BoardIterator begin();
    
    /**
    * Return a begin iterator over this board.
    *
    * @return ConstBoardIterator
    */
    ConstBoardIterator begin() const;

    /**
    * Return an end iterator over this board.
    *
    * @return BoardIterator
    */
    BoardIterator end();
    
    /**
    * Return an end iterator over this board.
    *
    * @return ConstBoardIterator
    */
    ConstBoardIterator end() const;

    /**
    * Return a tile at a specific location.
    *
    * @param const std::size_t x
    * @param const std::size_t y
    *
    * @throws std::out_of_range If the location (x,y) do not exist.
    *
    * @return TileInterface* Tile at the (x,y) location, while return nullptr
    *                        if the tile do not exist.
    */
    TileInterface* getTile(
      const std::size_t x,
      const std::size_t y
    );

    /**
    * Return a tile at a specific location.
    *
    * @param const std::size_t x
    * @param const std::size_t y
    *
    * @throws std::out_of_range If the location (x,y) do not exist.
    *
    * @return const TileInterface* Tile at the (x,y) location, while return nullptr
    *                        if the tile do not exist.
    */
    const TileInterface* getTile(
      const std::size_t x, const std::size_t y
    ) const;

    /**
    * Set a tile in a specific location.
    *
    * If a tile already exist at the location, this object will destroy it.
    *
    * @param const std::size_t x
    * @param const std::size_t y
    * @param gsl::owner<TileInterface*> tile Tile to set.
    *
    * @throws std::out_of_range If the location (x,y) do not exist.
    *
    * @return void
    */
    void setTile(
      const std::size_t x,
      const std::size_t y,
      gsl::owner<TileInterface*> tile
    );
    
    /**
    * Copy a tile in a specific location.
    *
    * If a tile already exist at the location, the board will destroy it.
    *
    * @param const std::size_t x
    * @param const std::size_t y
    * @param const TileInterface& tile Tile to set.
    *
    * @throws std::out_of_range If the location (x,y) do not exist.
    *
    * @return void
    */
    void setTile(
      const std::size_t x,
      const std::size_t y,
      const TileInterface& tile
    );

    /**
    * Check if a location is in the board.
    *
    * @param const std::size_t x
    * @param const std::size_t y
    *
    * @return bool True if the (x,y) location is in the board.
    */
    bool contains(
      const std::size_t x,
      const std::size_t y
    ) const;
    
    /**
     * Pass a turn.
     */
    virtual void nextTurn();
  protected:
    gsl::owner<TileInterface*>* tiles_;
    gsl::owner<Linearizer2D*> linearizer_;
};

#endif
