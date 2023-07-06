#pragma once
#include "Structs.h"

#include <string>

class Card
{
public:
	Card(std::string value = "E", CardTypes type = CardTypes::Empty);
	std::string getCardInfor();
	std::string getCardValue();
	std::string getCardType();

	void operator=(const Card& newCard)
	{
		cardType = newCard.cardType;
		cardValue = newCard.cardValue;
	}
private:
	CardTypes cardType = CardTypes::Empty;
	std::string cardValue;
};