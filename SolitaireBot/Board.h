#pragma once
#include "Deck.h"
#include <stack>
#include <array>
#include <iostream>
#include <cstdlib>

class Board
{
private:

	std::array<std::vector<Card>, 7> boardSlots;
	std::array<std::stack<Card>, 4> suitSlots;
	std::stack<Card> hand;
	

public:
	Deck deck;
	Board();
	void setBoard();
	void clearBoard();
	void dealThree();
	void printBoard();
	void printDeck();
};