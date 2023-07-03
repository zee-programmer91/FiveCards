#include "GetCardFrom.h"
#include "Command.h"

void GetCardFrom::ProcessFromContainer(Board* board, AvailableCommands command)
{
	Card newCard{ "X", CardTypes::Empty };
	std::string container;

	if (command == AvailableCommands::GetCardFromDeck)
	{
		newCard = board->getCardFromDeck();
		container = "Deck";
	}
	else
	{
		newCard = board->getCardFromGarbage(GarbageOptions::RetrieveCard);
		container = "Garbage";
	}

	auto& player = board->getPlayer();

	if (player.isComputer())
		std::cout << "--> The computer picked the following card from " << container << ": " << newCard.getCardInfor() << "\n\n";
	else
		std::cout << "--> The card you picked is: " << newCard.getCardInfor() << "\n\n";

	auto response = Command::GetCardResponse(board, newCard);
	board->processRequest(player, newCard, response);
}