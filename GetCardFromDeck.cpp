#include "GetCardFromDeck.h"
#include "Command.h"

#include <iostream>

bool GetCardFromDeck::execute(Board* board)
{
	auto newCard = board->getCardFromDeck();

	//	Changes cards for player 2 (Player 1 is computer so far)
	auto& player = board->getPlayer(2);

	std::cout << "The card you picked is: " << newCard.getCardInfor() << "\n\n";

	auto response = Command::getCardResponse();

	auto cardNumber = CardNumber::ONE;
	if ("2" == response)
		cardNumber = CardNumber::TWO;
	if ("3" == response)
		cardNumber = CardNumber::THREE;
	if ("4" == response)
		cardNumber = CardNumber::FOUR;
	if ("5" == response)
		cardNumber = CardNumber::FIVE;

	board->processRequest(player, cardNumber, newCard);

	return true;
}