#pragma once
#include <iostream>
#include "Board.h"

class ArtificialPlayer
{
private:
	Board *board;
	std::string nextCommand;
	std::string think();
	int drawCount = 0;

public:
	ArtificialPlayer(Board *board);
	std::string startNewGame();
	std::string getCommand();
};