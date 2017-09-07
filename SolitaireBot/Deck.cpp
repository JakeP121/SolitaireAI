#include "Deck.h"
#include <ctime>
Deck::Deck()
{
	srand(time(NULL));
	createDeck();
}

// Creates a new deck, ordered.
void Deck::createDeck()
{
	// Clear the cards vector
	cards.clear();

	int cardNum = 0;
	for (int j = 0; j < 4; j++) // Suits
	{
		for (int k = 0; k < 13; k++)	// Values
		{
			cards.push_back(Card(value[k], suit[j], cardNum));

			cardNum++;
		}
	}
}

// Swaps the position of two cards in the deck
void Deck::swapCardPositions(Card &cardOne, Card &cardTwo)
{
	Card tempCard = cardOne;	// Store cardOne in tempCard
	cardOne = cardTwo;			// Store cardTwo in cardOne
	cardTwo = tempCard;			// Store tempCard in cardTwo
}

// Creates a fresh deck
void Deck::sortDeck()
{
	createDeck();
}

// Shuffles the deck.
// <param>rounds: the amount of times the deck should be shuffled</param>
void Deck::shuffleDeck(int rounds)
{	
	while (rounds > 0)
	{
		for (std::vector<Card>::iterator iter = cards.begin(); iter != cards.end(); iter++)
		{
			// Get a random card from the deck
			int randomNum = rand() % cards.size();
			std::vector<Card>::iterator secondIter = cards.begin();
			std::advance(secondIter, randomNum);

			// Swap current card and random card
			swapCardPositions(*iter, *secondIter);
		}
		rounds--;
	}
}

// Returns a card from the deck
// <param>dealFaceDown: decides whether the card should be hidden when dealt</param>
Card Deck::dealCard(bool dealFaceDown)
{
	// Move iterator to last card
	std::vector<Card>::reverse_iterator rIter = cards.rbegin();

	// Store last card 
	Card returnCard = *rIter;

	// Delete last card from vector
	cards.pop_back();

	// If the card is meant to be delt face down, hide the card
	if (dealFaceDown)
		returnCard.setHidden(true);	

	// Return the stored last card
	return returnCard;
}

// Returns the amount of cards left in the deck
int Deck::getSize()
{
	return cards.size();
}

// Adds card to the deck
void Deck::addCard(Card card)
{
	cards.push_back(card);
}
