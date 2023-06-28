#include "GetCardFrom.h"
#include "Command.h"

void GetFrom::ProcessFromContainer(Board* board, AvailableCommands command)
{
	Card newCard{ "X", CardTypes::empty };

	if (command == AvailableCommands::GetCardFromDeck)
		newCard = board->getCardFromDeck();
	else
		newCard = board->getCardFromGarbage();

	//	Changes cards for player 2 (Player 1 is computer so far)
	auto& player = board->getPlayer();

	std::cout << "The card you picked is: " << newCard.getCardInfor() << "\n\n";

	auto response = Command::GetCardResponse();

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
}