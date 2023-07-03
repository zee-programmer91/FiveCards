#include "GetCardFrom.h"
#include "Command.h"

void GetCardFrom::ProcessFromContainer(Board* board, AvailableCommands command)
{
	Card newCard{ "X", CardTypes::Empty };

	if (command == AvailableCommands::GetCardFromDeck)
		newCard = board->getCardFromDeck();
	else
		newCard = board->getCardFromGarbage(GarbageOptions::RetrieveCard);

	auto& player = board->getPlayer();

	std::cout << "The card you picked is: " << newCard.getCardInfor() << "\n\n";

	auto response = Command::GetCardResponse(board, newCard);
	board->processRequest(player, newCard, response);
}