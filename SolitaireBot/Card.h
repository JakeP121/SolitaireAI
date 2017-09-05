#include <string>

class Card
{
private:
	std::string value;
	std::string suit;
	int cardNum;
	bool hidden = false;
	std::string colour;

public:
	Card()
	{
		value = "ACE";
		suit = "SPADES";
		cardNum = -1;
		colour = "BLACK";
	}
	Card(std::string value, std::string suit, int cardNum);
	std::string getValue();
	std::string getValueAbrv();
	void setValue(std::string value);
	std::string getSuit();
	void setSuit(std::string suit);
	int getCardNum();
	void setCardNum(int cardNum);
	void setHidden(bool hide);
	bool isHidden();
	std::string getColour();
	

};