#include "bot/AutoBot.hpp"

/**
* Create a simple bot.
*/
AutoBot::AutoBot() : SimpleBot() {}

/**
* Create a simple bot with a specific position.
*
* @param const int x
* @param const int y
*/
AutoBot::AutoBot(const int x, const int y) : SimpleBot(x,y) {}

/**
* Create a simple bot with a specific position.
*
* @param const Localizable2D&
*/
AutoBot::AutoBot(const Localizable2D& position) : SimpleBot(position) {}

/**
* Copy a generic bot.
*
* @param const Bot* toCopy
*/
AutoBot::AutoBot(const Bot* toCopy) : SimpleBot(toCopy) {}

/**
* Bot destructor.
*/
AutoBot::~AutoBot() {}

/**
*	Set instructions from a file
*/
void AutoBot::setInstructions(const std::string& filename) {
	
	std::ifstream infile(filename.c_str());
	std::string line;
	
	instructions.clear();

	while (std::getline(infile, line)) {
		instructions.push_back(line);
	}

}

/**
*	Set random instructions
*/
void AutoBot::setInstructions(int nbOfIntructions) {
	instructions.clear();

	while (instructions.size() < nbOfIntructions) {
		/* generate number between 1 and 5: */
		int nb = rand() % 5 + 1;

		switch (nb) {
		case 1:
			instructions.push_back("up");
			break;
		case 2:
			instructions.push_back("down");
			break;
		case 3:
			instructions.push_back("right");
			break;
		case 4:
			instructions.push_back("left");
			break;
		default:
			instructions.push_back("");
			break;

		}
	}
}


/**
* Pass a turn.
*/
void AutoBot::nextTurn()
{
	if (instructions.size() > 0) {
		std::string inst = instructions[0];

		if (inst == "left")
		{
			setX(getX() - 1);
		}
		else if (inst == "right") {
			setX(getX() + 1);
		}
		else if (inst == "up") {
			setY(getY() - 1);
		}
		else if (inst == "down") {
			setY(getY() + 1);
		}

		instructions.erase(instructions.begin(), instructions.begin()+1);
	}
} 

/**
* Allocate a copy of that bot.
*
* @return gsl::owner<Bot*>
*/
gsl::owner<Bot*> AutoBot::copy() const
{
  return new AutoBot(*this);
}