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
}