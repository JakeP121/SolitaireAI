#include "ArtificialPlayer.h"

ArtificialPlayer::ArtificialPlayer(Board * board)
{
	this->board = board;
	
	if (!board->boardSet)
		nextCommand = "NEWGAME";
	else
		nextCommand = "NULL";
}

std::string ArtificialPlayer::startNewGame()
{
	return "NEWGAME";
}

std::string ArtificialPlayer::getCommand()
{
	if (nextCommand != "NULL")
	{	
		std::string com = nextCommand;
		nextCommand = "NULL";
		return com;
	}

	if (board->hand.empty())
		return "DRAW";

	for (int i = 0; i < 4; i++)
	{

	}
}
