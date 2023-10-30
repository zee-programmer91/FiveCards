#include "Card.h"
#include <string>

Card::Card()
{
	
};

Card::Card(std::string cardValue, CardTypes cardType): value(cardValue), type(cardType) {};

std::string Card::getCardInfor()
{
	return value + getCardType();
};

std::string Card::getCardValue()
{
	return value;
};

std::string Card::getCardType()
{
	switch (type)
	{
	case CardTypes::Clubs:
		return "C";
	case CardTypes::Diamonds:
		return "D";
	case CardTypes::Hearts:
		return "H";
	case CardTypes::Spades:
		return "S";
	default:
		return "X";
	}
};