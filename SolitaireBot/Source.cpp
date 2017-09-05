#include "Board.h"
#include <iostream>

int main()
{
	Board myBoard;

	myBoard.deck.shuffleDeck(50);
	myBoard.setBoard();
	myBoard.printBoard();

	std::string command;

	while (true)
	{
		std::cin >> command;
		std::transform(command.begin(), command.end(), command.begin(), toupper);

		if (command == "EXIT")
			return 0;
		else
		{
			myBoard.handle(command);
			myBoard.printBoard();
		}
	}

	return 0;
}