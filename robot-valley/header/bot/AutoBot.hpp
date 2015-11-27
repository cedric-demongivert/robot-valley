#ifndef __AUTO_BOT_HPP
#define __AUTO_BOT_HPP

#include "bot/SimpleBot.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


/**
* @author Alexandre K/OURIO <kourio.alexandre@gmail.com>
*
* A bot with instructions.
*
* @class Bot
*/
class AutoBot
  : public SimpleBot
{
public:
  /**
  * Create a simple bot.
  */
	AutoBot();

  /**
  * Create a simple bot with a specific position.
  *
  * @param const int x
  * @param const int y
  */
	AutoBot(const int x, const int y);

  /**
  * Create a simple bot with a specific position.
  *
  * @param const Localizable2D&
  */
	AutoBot(const Localizable2D& position);

  /**
  * Copy a generic bot.
  *
  * @param const Bot* toCopy
  */
	AutoBot(const Bot* toCopy);

  /**
  * Bot destructor.
  */
  virtual ~AutoBot() override;

  /**
  *	Set instructions from a file
  */
  virtual void setInstructions(const std::string& filename);

  /**
  *	Set random instructions
  */
  virtual void setInstructions(int nbOfIntructions);


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


private:
	std::vector<std::string> instructions;
};

#endif
