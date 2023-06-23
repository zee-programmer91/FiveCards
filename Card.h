#pragma once

#include <string>

struct CardTypes
{
	std::string value = "";
};

class Card
{
public:
	Card(std::string value, std::string type);
	std::string getCardValue();
	std::string getCardType();
private:
	CardTypes hearts{ "HEARTS" };
	CardTypes clubs{ "CLUBS" };
	CardTypes diamonds{ "DIAMONDS" };
	CardTypes spades{ "SPADES" };

	CardTypes cardType;
	std::string cardValue;
};