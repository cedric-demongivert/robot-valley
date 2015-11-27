#include "tile/FactoryTile.hpp"

/**
*  @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*
*  A wall.
*/

FactoryTile::FactoryTile() : Tile() { nbTurn_create = init_nbTurnToCreate; };
FactoryTile::FactoryTile(Board* board) : Tile(board) { nbTurn_create = init_nbTurnToCreate; };
FactoryTile::FactoryTile(const TileInterface& toCopy) : Tile(toCopy) { nbTurn_create = init_nbTurnToCreate; };
FactoryTile::FactoryTile(const TileInterface& toCopy, Board* board) : Tile(toCopy, board) { nbTurn_create = init_nbTurnToCreate; };
FactoryTile::FactoryTile(const TileInterface& toCopy, Board* board, const int x, const int y) : Tile(toCopy, board, x, y) { nbTurn_create = init_nbTurnToCreate; };

FactoryTile::~FactoryTile()
{ }

bool FactoryTile::accept(const Bot& bot) const
{
  return false;
}

void FactoryTile::onEnter(Bot& bot)
{
  
}

void FactoryTile::onExit(Bot& bot)
{
  
}

gsl::owner<TileInterface*> FactoryTile::copy() const
{
  return new FactoryTile(*this);
}

int FactoryTile::getID() const
{
  return FACTORY_TILE_ID;
}

void FactoryTile::nextTurn() {
	
	BotManager* BM = getBoard()->getGame()->getBotManager();

	if (BM != nullptr && nbTurn_create <= 0 && this->isFree())
	{
		AutoBot* bot = new AutoBot(getX(), getY());
		bot->setInstructions(getBoard()->getGame()->getNbTurn());
		BM->addBot(bot);

		nbTurn_create = init_nbTurnToCreate;
	}
	else
		nbTurn_create--;
}

