#pragma once
#include "Deck.h"
#include "DataStructs.h"
#include <stack>
#include <array>
#include <iostream>
#include <cstdlib>
#include <string>

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
	int handle(std::string command);
	int move(point card, int column);
};