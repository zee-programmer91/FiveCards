#pragma once
#include "Structs.h"

#include <string>

class Card
{
public:
	Card(std::string value, CardTypes type);
	std::string getCardInfor();
	std::string getCardValue();
	std::string getCardType();

	void operator=(const Card& newCard)
	{
		cardType = newCard.cardType;
		cardValue = newCard.cardValue;
	}
private:
	CardTypes cardType = CardTypes::empty;
	std::string cardValue;
};