#pragma once
#include "CardEnums.h"
#include <string>

#ifdef CARD_EXPORTS
#define CARD_API __declspec(dllexport)
#else
#define CARD_API __declspec(dllimport)
#endif

struct Card
{
	std::string cardValue;
	CardTypes cardType;

	std::string getCardInfor()
	{
		return cardValue + getCardType();
	};

	std::string getCardValue()
	{
		return cardValue;
	};

	std::string getCardType()
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
	};
};