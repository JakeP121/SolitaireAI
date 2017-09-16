#pragma once
#include "Deck.h"
#include "DataStructs.h"
#include <stack>
#include <array>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

class Board
{
private:
	std::ofstream logFile;
	bool boardSet = false;
	void setBoard();	// Shuffle the deck and set the board
	void clearBoard();	// Clear the board and sort the deck
	void dealThree();	// Deal three cards into the hand
	void antiGarbage();	// Makes sure every card that is connected, has a pointer to it's connected card
	bool checkGameComplete();	// Checks if the game is completed
	
	int move(int column);	// Moves card from top of column to any first acceptable slot (suit slots prioritised)
	int move(int column, int destination);	// Moves card from top of column to destination
	int move(point card, int destination);	// Moves one or several cards beginning with at point card to destination

	

public:
	std::array<std::vector<Card>, 7> boardSlots;
	std::array<std::stack<Card>, 4> suitSlots;
	std::stack<Card> hand;
	Deck deck;

	Board();			// Opens the logFile for writing
	~Board();			// Saves and closes the logFile
	void printBoard();	// Print the board for the user to see
	void printDeck();	// Print the deck (debug)
	int handle(std::string command);	// Handle an input command
	bool isSet();		// Return if the board is set or not
	bool canMove(point card, std::vector<Card> &movingColumn, Card &movingCard); // Check if a card can move (not locked in by another card)
	
};