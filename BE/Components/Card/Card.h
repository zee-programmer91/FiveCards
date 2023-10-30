#pragma once
#include "CardEnums.h"
#include <string>

class Card
{
public:
	Card();
	Card(std::string value, CardTypes type);
	std::string getCardInfor();
	std::string getCardValue();
	std::string getCardType();
protected:
	std::string value;
	CardTypes type;
};