#include "Card.h"

Card::Card(std::string value, std::string suit, int cardNum)
{
	this->value = value;
	this->suit = suit;
	this->cardNum = cardNum;

	if ((suit == "CLUBS") || (suit == "SPADES"))
		colour = "BLACK";
	else if ((suit == "DIAMONDS") || (suit == "HEARTS"))
		colour = "RED";
	else
		throw std::exception();
}

std::string Card::getValue()
{
	if (!hidden)
		return value;
	else
		return "HIDDEN";
}

std::string Card::getValueAbrv()
{
	int cardVal = cardNum % 13;

	switch (cardVal)
	{
	case (0):
		return "A";
	case(1):
		return "2";
	case(2):
		return "3";
	case(3):
		return "4";
	case(4):
		return "5";
	case(5):
		return "6";
	case(6):
		return "7";
	case(7):
		return "8";
	case(8):
		return "9";
	case(9):
		return "10";
	case(10):
		return "J";
	case(11):
		return "Q";
	case(12):
		return "K";
	default:
		return "0";
	}
}

int Card::getValueNum()
{
	return cardNum % 13;
}

void Card::setValue(std::string value)
{
	this->value = value;
}

std::string Card::getSuit()
{
	if (!hidden)
		return suit;
	else
		return "HIDDEN";
}

void Card::setSuit(std::string suit)
{
	this->suit = suit;
}

int Card::getCardNum()
{
	if (!hidden)
		return cardNum;
	else
		return -1;
}

void Card::setCardNum(int cardNum)
{
	this->cardNum = cardNum;
}

void Card::setHidden(bool hide)
{
	hidden = hide;
}

bool Card::isHidden()
{
	return hidden;
}

std::string Card::getColour()
{
	return colour;
}

Card* Card::getConnectedCard()
{
	if (connectedCard)
		return connectedCard;
	else
		return nullptr;
}

void Card::setConnectedCard(Card *card)
{
	connectedCard = card;
}
