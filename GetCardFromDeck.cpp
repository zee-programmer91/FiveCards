#include "GetCardFromDeck.h"
#include "Command.h"

#include <iostream>

bool GetCardFromDeck::execute(Board* board)
{
	auto card = board->getCardFromDeck();

	//	Changes cards for player 2 (Player 1 is computer so far)
	auto& player = board->getPlayer(2);

	std::cout << "The card you picked is: " << card.getCardInfor() << "\n\n";

	auto response = Command::getCardResponse();

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