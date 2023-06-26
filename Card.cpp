#include "Card.h"

Card::Card(std::string value, CardTypes type) : cardValue(value), cardType(type){}

std::string Card::getCardInfor()
{
	return getCardValue() + getCardType();
}

std::string Card::getCardValue()
{
	return cardValue;
}

std::string Card::getCardType()
{
	switch (cardType)
	{
		case CardTypes::clubs:
			return "C";
		case CardTypes::diamonds:
			return "D";
		case CardTypes::hearts:
			return "H";
		case CardTypes::spades:
			return "S";
		default:
			return "X";
	}
}