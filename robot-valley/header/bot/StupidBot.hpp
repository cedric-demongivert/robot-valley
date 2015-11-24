#ifndef __STUPID_BOT_HPP
#define __STUPID_BOT_HPP

#include "bot/SimpleBot.hpp"

/**
* @author Cédric DEMONGIVERT <cedric.demongivert@gmail.com>
*
* A very stupid bot.
*
* @class SimpleBot
*/
class StupidBot
  : public SimpleBot
{
public:
  /**
  * Create a simple bot.
  */
  StupidBot();

  /**
  * Create a simple bot with a specific position.
  *
  * @param const int x
  * @param const int y
  */
  StupidBot(const int x, const int y);

  /**
  * Create a simple bot with a specific position.
  *
  * @param const Localizable2D&
  */
  StupidBot(const Localizable2D& position);

  /**
  * Copy a generic bot.
  *
  * @param const Bot* toCopy
  */
  StupidBot(const Bot* toCopy);

  /**
  * Bot destructor.
  */
  virtual ~StupidBot() override;

  /**
  * Pass a turn.
  */
  virtual void nextTurn() override;

  /**
  * Allocate a copy of that bot.
  *
  * @return gsl::owner<Bot*>
  */
  virtual gsl::owner<Bot*> copy() const override;

};

#endif
