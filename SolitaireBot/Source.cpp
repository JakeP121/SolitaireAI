#include "Board.h"
#include <iostream>

int main()
{
	Board myBoard;

	char input[20];

	myBoard.handle("NEWGAME");
	myBoard.handle("DRAW");
	myBoard.printBoard();

	while (true)
	{
		std::cin.getline(input, sizeof(input));

		for (int i = 0; i < sizeof(input); i++)
			input[i] = toupper(input[i]);

		std::string command = input;

		if (command == "EXIT")
			return 0;
		else if (command == "BREAK")
			myBoard.printBoard();
		else
		{
			myBoard.handle(command);
			system("cls");
			myBoard.printBoard();
		}
	}

	/////////////////////////
	//
	// I broke it again.
	//
	// 
	// Blame Christie.
	//
	// If two or more cards are moved
	// between columns, the locked cards
	// still reference the old positions
	// of cards above them, therefore 
	// creating blank card.
	//
	/////////////////////////





	return 0;
}