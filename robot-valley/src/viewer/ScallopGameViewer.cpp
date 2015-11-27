#include "viewer/ScallopGameViewer.hpp"

ScallopGameViewer::ScallopGameViewer(gsl::not_null<Game*> game)
  : game_(game)
{

  std::size_t width = game->getBoard()->getWidth();

  if (width < 50) width = 50;

  shell_ = new SDLScallopShell("robot-valley", width, game->getBoard()->getHeight() + 1);
  shell_->nextln("Press space for an extra turn !");

}

ScallopGameViewer::~ScallopGameViewer()
{
  delete shell_;
  shell_ = nullptr;
}

void ScallopGameViewer::run()
{
  for (std::size_t index = 1; index < game_->getNbTurn(); ++index)
  {
    shell_->setCursor(0, 0);
    shell_->next("Press space for an extra turn ! ( ");
    shell_->next(std::to_string(index));
    shell_->next(" / ");
    shell_->next(std::to_string(game_->getNbTurn()));
    shell_->nextln(" )");
    printBoard();
    printBots();
    shell_->render();
    shell_->waitEnter();
    game_->nextTurn();
  }
}

void ScallopGameViewer::printBoard()
{
  int offsetX = -game_->getBoard()->getX();
  int offsetY = -game_->getBoard()->getY();

  for (auto it = game_->getBoard()->begin(); it != game_->getBoard()->end(); ++it)
  {
    shell_->setChar(offsetY + it->getY() + 1, offsetX + it->getX(), getTileChar(*(*it)));
  }
}

char ScallopGameViewer::getTileChar(const TileInterface& tile) const
{
  switch (tile.getID())
  {
    case TILE_ID: return '.';
    case WALL_TILE_ID: return '#';
	case FACTORY_TILE_ID: return 'F';
    default: return '?';
  }
}

void ScallopGameViewer::printBots()
{
  BotManager* manager = game_->getBotManager();

  for (std::size_t index = 0; index < manager->size(); ++index) {
    Bot* bot = manager->getBot(index);
    shell_->setChar(bot->getY() +1, bot->getX(), 'B');
  }
}