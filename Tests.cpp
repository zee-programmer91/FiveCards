#include "Card.h"
#include "Tests.h"

#include <iostream>

bool Tests::runTests()
{
	if (!testCard())
		return false;

	return true;
}

bool Tests::testCard()
{
	Card card{ "1", "H" };

	if ("1" != card.getCardValue())
	{
		std::cout << "getCardValue()\nExpected: \"1\"\nActual: "
			        << card.getCardValue() << "\n";
		return false;
	}

	if ("HEARTS" != card.getCardType())
	{
		std::cout << "getCardType()\nExpected: C\nActual: "
			<< card.getCardType() << "\n";
		return false;
	}

	return true;
}
