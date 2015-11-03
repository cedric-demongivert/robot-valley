#ifndef __TILE_INTERFACE_HPP
#define __TILE_INTERFACE_HPP

/**
 * @author K/OURIO Alexandre <kourio.alexandre@gmail.com>
 * */



class BoardInterface;
class Board;
class Bot;


class TileInterface{
	
public:

	virtual ~TileInterface();

	
	/**
	 *	Get the Board the tile is in
	 * 
	 *	@return Board*
	 */
	virtual const Board* getBoard() const =0;	
	virtual Board* getBoard() =0;
	
	/**
	 *	Get the bot on the tile
	 * 
	 *	@return Bot* or nullptr if no bot on the tile
	 */
	virtual const Bot* getBot() const =0;
	virtual Bot* getBot() =0;
	
	/**
	 *	If there is nothing on the tile
	 * 
	 *	@return bool
	 */
	virtual bool isFree() const =0;
	
	/**
	 *	Called when a bot enters the tile
	 * 
	 * 	@throws TileNotFreeException - the tile isn't free.
	 * 
	 * 	@param Bot& bot The bot that enters the tile
	 */
	virtual void onEnter(Bot& bot) =0;
	
	/**
	 *	Called when a bot leaves the tile
	 * 
	 * 	@throws TileFreeException - No Bot on tile so it can't leave it
	 * 
	 * 	@param Bot& bot The bot that leaves the tile
	 */
	virtual void onExit(Bot& bot) =0;
	
}



#endif
