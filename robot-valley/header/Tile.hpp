#ifndef __TILE_HPP
#define __TILE_HPP

#include "TileInterface.hpp"
#include "board/Board.hpp"
#include "bot/bot.hpp"

#define TILE_ID 0


/**
 *  @author K/OURIO Alexandre <kourio.alexandre@gmail.com>
 * 
 *  A basic Tile that implement TileInterface.
 * 
 *  @class TileInterface
 */
 
class Tile: public TileInterface
{
  public:
    Tile();
    Tile(Board* board);
    Tile(const TileInterface& toCopy);
    Tile(const TileInterface& toCopy, Board* board);
    Tile(const TileInterface& toCopy, Board* board, const int x, const int y);

    virtual ~Tile();

    const Board* getBoard() const override;
    Board* getBoard() override;

    void setBoard(Board* newBoard) override;

    const Bot* getBot() const override;
    Bot* getBot() override;

    bool isFree() const override;

    virtual bool accept(const Bot& bot) const override;
    virtual void onEnter(Bot& bot) override;
    virtual void onExit(Bot& bot) override;

    virtual gsl::owner<TileInterface*> copy() const override;
	  
	  int getX() const override;
	  int getY() const override;

    inline void setX(const int x) override {
      setLocation(x, getY());
    }

    inline void setY(const int y) override {
      setLocation(getX(), y);
    }

    void setLocation(const int x, const int y) override;
	
	  virtual void nextTurn() override;

    virtual int getID() const override;

  private:
    Board* board_;
    
	  int x_;
	  int y_;
};

#endif
