#include "Card.h"

Card::Card(std::string value, std::string type) : cardValue(value)
{
	if ("C" == type || "c" == type)
		cardType = clubs;
	else if ("D" == type || "d" == type)
		cardType = diamonds;
	else if ("H" == type || "h" == type)
		cardType = hearts;
	else if ("S" == type || "s" == type)
		cardType = spades;
}

std::string Card::getCardValue()
{
	return cardValue;
}

std::string Card::getCardType()
{
	return cardType.value;
}