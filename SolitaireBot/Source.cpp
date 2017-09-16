#include "Board.h"
#include <iostream>
#include "ArtificialPlayer.h"
#include <Windows.h>

int main()
{
	Board myBoard;
	ArtificialPlayer myAI(&myBoard);

	char input[20];

	do
	{
		std::string command = myAI.getCommand();
		myBoard.handle(command);
		Sleep(100);
	} while (myBoard.isSet());


	
	/*		HUMAN CONTROL
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
	*/

	return 0;
}