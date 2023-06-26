#include "Tests.h"

bool Tests::runTests()
{
	if (!testCard())
		return false;

	if (!testCommand())
		return false;

	if (!testDeck())
		return false;

	if (!testHelper())
		return false;

	if (!testPlayer())
		return false;

	return true;
}

bool Tests::testCard()
{
	Card card{ "1", CardTypes::hearts };

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

bool Tests::testCommand()
{
	Command command{ "CommandTest" };
	if ("CommandTest" != command.getCommandName())
	{
		std::cout << "Command.getCommandName()\nExpected: \"CommandTest\"\nActual: "
			<< command.getCommandName() << "\n";
		return false;
	}

	auto validCommand1 = GetCardFromDeck();
	if (!validCommand1.execute())
	{
		std::cout << "GetCardFromDeck.execute()\nExpected: true\nActual: false\n";
		return false;
	}

	auto validCommand2 = GetCardFromGarbage();
	if (!validCommand2.execute())
	{
		std::cout << "GetCardFromGarbage.execute()\nExpected: \"true\"\nActual: false\n";
		return false;
	}

	auto invalidCommand = Command("FaillingCommand");
	if (invalidCommand.execute())
	{
		std::cout << "FaillingCommand.execute()\nExpected: \"false\"\nActual: true\n";
		return false;
	}

	return true;
}

bool Tests::testHelper()
{
	auto phrases = Helper::split("one two three", ' ');

	if (3 != phrases.size())
	{
		std::cout << "Helper.split()\nExpected: \"3\"\nActual: "
			<< phrases.size() << "\n";
		return false;
	}

	phrases = Helper::split("one,two,three,four", ',');

	if (4 != phrases.size())
	{
		std::cout << "Helper.split()\nExpected: \"4\"\nActual: "
			<< phrases.size() << "\n";
		return false;
	}

	return true;
}

bool Tests::testDeck()
{
	Deck deck{};
	auto size = deck.getAllDeckCards().size();

	if (52 != size)
	{
		std::cout << "Deck.getAllDeckCards()\nExpected: 52\nActual: "
			<< deck.getAllDeckCards().size() << "\n";
		return false;
	}

	return true;
}

bool Tests::testPlayer()
{
	Player player{};
	player.setCard(3, Card{"2", CardTypes::hearts });

	auto thirdCard = player.getCard(3);

	if ("2" != thirdCard.getCardValue())
	{
		std::cout << "Player.getCardValue()\nExpected: 2\nActual: "
			<< thirdCard.getCardValue() << "\n";
		return false;
	}

	if ("H" != thirdCard.getCardType())
	{
		std::cout << "Player.getCardValue()\nExpected: H\nActual: "
			<< thirdCard.getCardType() << "\n";
		return false;
	}

	return true;
}