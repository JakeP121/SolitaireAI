#pragma once
#include <iostream>
#include "Board.h"

class ArtificialPlayer
{
private:
	Board *board;
	std::string nextCommand;
	std::string think();

public:
	ArtificialPlayer(Board *board);
	std::string startNewGame();
	std::string getCommand();
};