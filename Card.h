#pragma once
#include "Structs.h"

#include <string>

class Card
{
public:
	Card(std::string value, std::string type);
	std::string getCardValue();
	std::string getCardType();

	void operator=(const Card& newCard)
	{
		cardType.value = newCard.cardType.value;
		cardValue = newCard.cardValue;
	}
private:
	CardTypes hearts{ "H" };
	CardTypes clubs{ "C" };
	CardTypes diamonds{ "D" };
	CardTypes spades{ "H" };
	CardTypes empty{ "E" };

	CardTypes cardType;
	std::string cardValue;
};