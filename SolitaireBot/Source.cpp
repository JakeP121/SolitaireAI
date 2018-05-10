#include "Board.h"
#include <iostream>
#include "ArtificialPlayer.h"
#include <Windows.h>

/// <summary>
/// Runs a game of solitaire with AI input
/// </summary>
/// <param name="gameBoard">The solitaire game that is going to be played</param>
void runAI(Board *gameBoard)
{
	ArtificialPlayer myAI(gameBoard);

	char input[20]; // Input buffer

	gameBoard->printBoard();
	Sleep(10);

	do
	{
		gameBoard->printBoard();

		std::string command = myAI.getCommand();

		if (command == "EXIT")
			return;

		gameBoard->handle(command);
		std::cout << "\tAI says: " << command << "\n";
		
		Sleep(500);
	} while (gameBoard->isSet());
}

/// <summary>
/// Runs a game of solitaire with human input
/// </summary>
/// <param name="gameBoard">The solitaire game that is going to be played</param>
void runHuman(Board *gameBoard)
{
	ArtificialPlayer myAI(gameBoard);

	char input[20]; // Input buffer

	while (true)
	{
		std::cin.getline(input, sizeof(input));

		for (int i = 0; i < sizeof(input); i++)
			input[i] = toupper(input[i]);

		std::string command = input;

		if (command == "EXIT")
			return;
		else
		{
			gameBoard->handle(command);
			system("cls");
			gameBoard->printBoard();
		}
	}
}



int main()
{
	Board myBoard; // Solitaire board

	runAI(&myBoard);
	//runHuman(&myBoard);

	Sleep(5000); // Wait 5 seconds
	return 0;
}