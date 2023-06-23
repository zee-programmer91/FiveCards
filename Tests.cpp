#include "Tests.h"


bool Tests::runTests()
{
	if (!testCard())
		return false;

	if (!testDeck())
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

bool Tests::testDeck()
{
	Deck deck{};
	std::set<std::string> mySet{};

	for (int count = 1; count <= 52; count++)
	{
		auto card = deck.getNextCard();
		mySet.insert(card.getCardValue() + card.getCardType());
	}

	if (52 != mySet.size())
		return false;

	return true;
}