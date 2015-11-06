#ifndef __BOARD_HPP
#define __BOARD_HPP

#include <cstdlib>
#include <stdexcept>
#include "Board.hpp"
#include "HorizontalLinearizer2D.hpp"

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
    virtual std::size_t getHeight() const override;

    /**
    * Return the board width.
    *
    * @return std::size_t
    */
    virtual std::size_t getWidth() const override;

    /**
    * Return a begin iterator over this board.
    *
    * @return BoardIterator
    */
    virtual BoardIterator begin() override;
    virtual ConstBoardIterator begin() const override;

    /**
    * Return an end iterator over this board.
    *
    * @return BoardIterator
    */
    virtual BoardIterator end() override;
    virtual ConstBoardIterator end() const override;

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
    virtual TileInterface* getTile(
      const std::size_t x,
      const std::size_t y
    ) override;

    virtual const TileInterface* getTile(
      const std::size_t x, const std::size_t y
    ) const override;

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
    virtual void setTile(
      const std::size_t x,
      const std::size_t y,
      gsl::owner<TileInterface*> tile
    ) override;

    /**
    * Check if a location is in the board.
    *
    * @param const std::size_t x
    * @param const std::size_t y
    *
    * @return bool True if the (x,y) location is in the board.
    */
    virtual bool contains(
      const std::size_t x,
      const std::size_t y
    ) const = 0;

  protected:
    gsl::owner<TileInterface*>* tiles_;
    gsl::owner<Linearizer2D*> linearizer_;
};

#endif
