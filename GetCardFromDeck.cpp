#include "GetCardFromDeck.h"

#include <iostream>

bool GetCardFromDeck::execute(Board* board)
{
	auto card = board->getCardFromDeck();

	//	Changes cards for player 2 (Player 1 is computer so far)
	auto& player = board->getPlayer(2);

	std::cout << "The card you picked is: " << card.getCardInfor() << "\n";

	std::string response;
	while (true)
	{
		std::cout << "Which card do you want to replaced?\n";
		std::cout << "1 - Card 1\n";
		std::cout << "2 - Card 2\n";
		std::cout << "3 - Card 3\n";
		std::cout << "4 - Card 4\n";
		std::cout << "5 - Card 5\n";
		std::cin >> response;

		if ("1" != response && "2" != response && "3" != response && "4" != response && "5" != response)
			std::cout << "ERROR: CARD NUMBER '" << response << "' DOES NOT EXIST.\nTRY AGAIN\n";
		else
			break;
	}

	if ("1" == response)
		player.setCard(CardNumber::ONE, card);

	else if ("2" == response)
		player.setCard(CardNumber::TWO, card);

	else if ("3" == response)
		player.setCard(CardNumber::THREE, card);

	else if ("4" == response)
		player.setCard(CardNumber::FOUR, card);

	else if ("5" == response)
		player.setCard(CardNumber::FIVE, card);

	return true;
}