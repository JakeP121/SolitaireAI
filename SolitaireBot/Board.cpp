#include "Board.h"

Board::Board()
{
	// Constructor empty
}

// Sets the board with fresh cards
void Board::setBoard()
{
	int cardsPerSlot = 1; // How many cards should be dealt into each column (start at 1, end at 7)

	for (int i = 0; i < 7; i++) // Loop through board slots
	{
		for (int j = 0; j < cardsPerSlot; j++) // Loop for how many cards should be added to this column
		{
			if (j < cardsPerSlot - 1)	// If the next card isn't going to be at the front of the slot
				boardSlots[i].push_back(deck.dealCard(true));	// hide it 
			else
				boardSlots[i].push_back(deck.dealCard(false));	// show it 
		}

		// increment the cardsPerSlot for the next column
		cardsPerSlot++;
	}
}

// Clears the board and resets the deck
void Board::clearBoard()
{
	// Clear board slots
	for (int i = 0; i < 7; i++)
	{
		while(!boardSlots[i].empty())
			boardSlots[i].pop_back();
	}

	// Clear suit slots
	for (int i = 0; i < 4; i++)
	{
		while (!suitSlots[i].empty())
			suitSlots[i].pop();
	}


	// Clear hand
	while (!hand.empty())
		hand.pop();

	// Create a new, ordered deck
	deck.sortDeck();

	// Clear the screen
	std::system("cls");
}

// Tries to deal three cards from the deck to the hand
void Board::dealThree()
{
	// If there is no more cards to draw
	if (deck.getSize() == 0)
	{
		while (!hand.empty()) // Deal hand back into deck
		{
			deck.addCard(hand.top());
			hand.pop();
		}
		return;
	}

	int cardsDealt = 0;
	std::stack<Card> tempHand;

	// While there are cards left in the hand, and less than three cards have been drawn
	while (cardsDealt < 3 && deck.getSize() != 0)
	{
		tempHand.push(deck.dealCard());	// Push cards from the deck into the hand

		cardsDealt++;				// Increment the amount of cards dealt
	}

	for (int i = 0; i < cardsDealt; i++)
	{
		hand.push(tempHand.top());
		tempHand.pop();
	}

}

// Prints the current board to the console
void Board::printBoard()
{
	// Clear the screen
	std::system("cls");

	/////////////////////////////////// Draw suit slots
	std::cout << "  ";

	for (int i = 0; i < 4; i++) // Loop through the four slots
	{
		if (suitSlots[i].empty())	// If the slot is empty
		{
			std::cout << "[   ]" << "\t\t";	// Draw a blank card
		}
		else						// If the slot is not empty
		{
			// Get the top card of that slot and store its suit and value
			Card curCard = suitSlots[i].top();
			std::string suit = curCard.getSuit();
			std::string value = curCard.getValueAbrv();

			// Output
			std::cout << "[" << value << suit[0];
			
			// Add an extra space if the value isn't double digits
			if (value != "10")
				std::cout << " " << suit[0] << "\t\t";
			else
				std::cout << suit[0] << "\t\t";
		}
	}


	std::cout << "\n\n";


	///////////////////////////////////// Draw board slots

	bool finished = false;	// Gets flipped to true when all slots are drawn to stop the loop
	int row = 0;			// The current row being drawn

	while (!finished)		// While drawing isn't finished
	{
		bool cardDrawn = false;	// Gets flipped to true if a card has been drawn this turn (to sense when to stop looping)

		for (int i = 0; i < 7; i++) // Loop across slots
		{
			if (boardSlots[i].size() > row)	// If the current slot has a card in the current row
			{
				// Get the card of this row and column
				std::vector<Card>::iterator iter = boardSlots[i].begin();
				std::advance(iter, row);
				Card curCard = *iter;

				
				if (curCard.isHidden())	// If the card is hidden, draw a blank card
					std::cout << "[   ]\t";
				else					// Else, if the card is not hidden
				{
					// Store the suit and value of the card
					std::string suit = curCard.getSuit();
					std::string value = curCard.getValueAbrv();


					// Output
					std::cout << "[" << value;
					
					// Draw an extra space if value is double digit
					if (value != "10")
						std::cout << " " << suit[0] << "]\t";
					else
						std::cout << suit[0] << "]\t";
				}

				// Set cardDrawn to true so it can loop next turn too.
				cardDrawn = true;
			}
			else
			{
				// If this column doesn't have a card in this rown, tab across to the next column
				std::cout << "\t";
			}
		}

		// Move onto the next row
		row++; 
		std::cout << "\n";

		// If no card has been drawn this turn, signal that drawing has finished
		if (!cardDrawn)
			finished = true;
	}

	std::cout << "\n\n\t";

	///////////////////////////////////// Draw hand
	if (hand.size() == 0) // If there is no hand, end prematurely
		return;

	std::vector<Card> visibleHand;

	// Store the size of the hand, but cap it at three (only the top 3 cards should be drawn)
	int handSize = hand.size();
	if (handSize > 3)
		handSize = 3;

	// Loop through the top 3 or less cards in the hand and store them in visibleHand 
	for (int i = 0; i < handSize; i++)
	{
		visibleHand.push_back(hand.top());
		hand.pop();
	}
	
	// Loop through visible hand
	for (std::vector<Card>::iterator iter = visibleHand.begin(); iter != visibleHand.end(); iter++)
	{
		// Get the card and store its suit and value
		Card curCard = *iter;
		std::string suit = curCard.getSuit();
		std::string value = curCard.getValueAbrv();

		// Output
		std::cout << "[" << value;

		// Print an extra space if the value is single-digit
		if (value != "10")
			std::cout << " " << suit[0] << "]\t";
		else
			std::cout << suit[0] << "]\t";

		// Push this card back into the hand
		hand.push(*iter);
	}
}

// Prints the deck (debug)
void Board::printDeck()
{
	while (deck.getSize() > 0)
	{
		Card curCard = deck.dealCard();
		std::string suit = curCard.getSuit();
		std::string value = curCard.getValue();

		std::cout << suit << " " << value << "\n";
	}
}

int Board::handle(std::string command)
{
	if (command == "DRAW")
	{
		dealThree();
		return 0;
	}
	else if (command == "NEWGAME")
	{
		clearBoard();
		setBoard();
	}
}