#include "Board.h"

int main()
{
	Board myBoard;

	myBoard.deck.shuffleDeck(50);
	myBoard.setBoard();
	myBoard.printBoard();

	for (int i = 0; i < 50; i++)
	{
		myBoard.dealThree();
		myBoard.printBoard();
	}

	/////////////////////////
	//
	// Fix this ^
	//
	// If three cards (AC, 2D,
	// 3H) are dealt, they 
	// will be flipped by the
	// time they next come
	// around (3H, 2D, AC).
	//
	// Happens to every 
	// dealt triplet.
	//
	/////////////////////////

	return 0;
}