#ifndef __BOARD_HPP
#define __BOARD_HPP

#include "BoardInterface.hpp"
#include "BoardIteratorInterface.hpp"
#include "BoardIterator.hpp"
#include "TileInterface.hpp"

/**
* @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*
* A basic constant implementation of BoardInterface that use a linear Array
* for storing tiles.
*
* @class BoardInterface
*/
class Board : public BoardInterface
{
  public:
    /**
    * Create a simple empty board.
    *
    * @param const size_t width
    * @param const size_t height
    */
    Board(const size_t width, const size_t height);

    /**
    * Copy an existing board (deep-copy).
    *
    * @param const BoardInterface& toCopy
    */
    Board(const BoardInterface& toCopy);

    /**
    * Board destructor, the board will destroy its tiles.
    */
    virtual ~Board();

    /**
    * Return the board height.
    *
    * @return size_t
    */
    virtual std::size_t getHeight() const override;

    /**
    * Return the board width.
    *
    * @return size_t
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
    * @param const int x
    * @param const int y
    *
    * @throws BoardOutOfBoundsException If the location (x,y) do not exist.
    *
    * @return TileInterface* Tile at the (x,y) location, while return nullptr if the tile do not exist.
    */
    virtual TileInterface* getTile(const int x, const int y) override;
    virtual const TileInterface* getTile(
      const int x, const int y
    ) const override;

    /**
    * Set a tile in a specific location.
    *
    * If a tile already exist at the location, this object will destroy it.
    *
    * @param const int x
    * @param const int y
    * @param TileInterface* tile Tile to set.
    *
    * @throws BoardOutOfBoundsException If the location (x,y) do not exist.
    *
    * @return void
    */
    virtual void setTile(
      const int x, const int y, TileInterface* tile
    ) override;

    /**
    * Check if a location is in the board.
    *
    * @param const int x
    * @param const int y
    *
    * @return bool True if the (x,y) location is in the board.
    */
    virtual bool isIn(const int x, const int y) const override;

  protected:
    TileInterface* tiles_;
    std::size_t height_;
    std::size_t width_;
};

#endif
