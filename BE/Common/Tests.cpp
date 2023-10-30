#include "Tests.h"
#include "../Components/Display/Display.h"

bool Tests::RunTests()
{
	if (!TestCard())
		return false;

	if (!TestDeck())
		return false;

	if (!TestHelper())
		return false;

	if (!TestPlayer())
		return false;

	return true;
}

bool Tests::TestCard()
{
	Card card{ "1", CardTypes::Hearts };

	if ("1" != card.getCardValue())
	{
		std::cout << "Card.()\nExpected: \"1\"\nActual: "
			        << card.getCardValue() << "\n";
		return false;
	}

	if ("H" != card.getCardType())
	{
		std::cout << "Card.getCardType()\nExpected: H\nActual: "
			<< card.getCardType() << "\n";
		return false;
	}

	return true;
}

bool Tests::TestHelper()
{
	auto phrases = Helper::Split("one two three", ' ');

	if (3 != phrases.size())
	{
		std::cout << "Helper.split()\nExpected: \"3\"\nActual: "
			<< phrases.size() << "\n";
		return false;
	}

	phrases = Helper::Split("one,two,three,four", ',');

	if (4 != phrases.size())
	{
		std::cout << "Helper.split()\nExpected: \"4\"\nActual: "
			<< phrases.size() << "\n";
		return false;
	}

	return true;
}

bool Tests::TestDeck()
{
	Deck deck{};
	auto size = deck.getAllDeckCards().size();

	if (52 != size)
	{
		Display::NormalMessage("Deck.getAllDeckCards()\nExpected: 52\nActual: ");
		std::cout << deck.getAllDeckCards().size() << "\n";
		return false;
	}

	return true;
}

bool Tests::TestPlayer()
{
	Player player{};
	player.setCard(3, Card{"2", CardTypes::Hearts });

	auto thirdCard = player.getCard(3);

	if ("2" != thirdCard.getCardValue())
	{
		Display::NormalMessage("Player.getCardValue()\nExpected: 2\nActual: ");
		Display::NormalMessage(thirdCard.getCardValue());
		Display::NormalMessage("\n");
		return false;
	}

	if ("H" != thirdCard.getCardType())
	{
		Display::NormalMessage("Player.getCardValue()\nExpected: H\nActual: ");
		Display::NormalMessage(thirdCard.getCardType());
		Display::NormalMessage("\n");
		return false;
	}

	return true;
}