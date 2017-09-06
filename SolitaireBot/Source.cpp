#include "Board.h"
#include <iostream>

int main()
{
	Board myBoard;

	myBoard.deck.shuffleDeck(50);
	myBoard.setBoard();
	myBoard.printBoard();

	char command[20];

	while (true)
	{
		std::cin.getline(command, sizeof(command));

		for (int i = 0; i < sizeof(command); i++)
			command[i] = toupper(command[i]);

		if (command == "EXIT")
			return 0;
		else if (command == "")
			std::cout << "Stopping\n";
		else
		{
			myBoard.handle(command);
			myBoard.printBoard();
		}
	}

	/////////////////////////
	//
	// Fix the glitch that
	// stops for testing 
	// the command as a 
	// string and not a char
	// array.
	//
	// Also fix whatever tf
	// glitch is stopping
	// cards getting shown
	// when boardSlots
	// size > 7
	//
	/////////////////////////





	return 0;
}