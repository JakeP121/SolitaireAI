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
	bool boardSet = false;
	bool canMove(point card, std::vector<Card> &movingColumn, Card &movingCard);

public:
	Deck deck;
	Board();
	void setBoard();
	void clearBoard();
	void dealThree();
	void printBoard();
	void printDeck();
	int handle(std::string command);
	int move(int column);	// Moves card from top of column to any first acceptable slot (suit slots prioritised)
	int move(int column, int destination);	// Moves card from top of column to destination
	int move(point card, int destination);	// Moves one or several cards beginning with at point card to destination
};