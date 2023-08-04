#include "FiveCardsEngine.h"

bool FiveCardsEngine::runGame(Board* board)
{
	auto request = Command::GetUserCommand(board);

	if (request == AvailableCommands::Exit)
	{
		return Command::HandleRequest<Exit>(board);
	}

	else if (request == AvailableCommands::GetCardFromDeck)
	{
		return Command::HandleRequest<GetCardFromDeck>(board);
	}

	return Command::HandleRequest<GetCardFromGarbage>(board);
}