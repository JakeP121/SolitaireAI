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
			std::cout << "Stopping\n";
		else
		{
			myBoard.handle(command);
			system("cls");
			myBoard.printBoard();
		}
	}

	/////////////////////////
	//
	// Crashes when moving
	// an entire column,
	// leaving an empty one.
	//
	/////////////////////////





	return 0;
}