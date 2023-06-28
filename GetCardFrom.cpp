#include "GetCardFrom.h"
#include "Command.h"

void GetFrom::ProcessFromContainer(Board* board, AvailableCommands command)
{
	Card newCard{ "X", CardTypes::empty };

	if (command == AvailableCommands::GetCardFromDeck)
		newCard = board->getCardFromDeck();
	else
		newCard = board->getCardFromGarbage();

	auto& player = board->getPlayer();

	std::cout << "The card you picked is: " << newCard.getCardInfor() << "\n\n";

	auto response = Command::GetCardResponse();
	board->processRequest(player, newCard, response);
}