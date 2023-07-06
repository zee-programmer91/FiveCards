#include "Command.h"
#include "Display.h"

AvailableCommands Command::GetUserCommand(Board* board)
{
	std::string response;

	while (true)
	{
		board->displayBoard();

		if (board->changePlayer)
		{
			board->changePlayerTurn();
			board->changePlayer = false;
		}

		auto player = board->getPlayer();

		if (!player.isComputer())
		{
			Display::CommandPrompt();

			response = Display::GetInput();

			if ("1" != response && "2" != response && "3" != response)
				Display::CommandError("ERROR: COMMNAND '", response);
			else
				break;
		}
		else
		{
			Display::ComputerTurn();
			response = board->getComputerResponse(ComputerResponses::CommandResponse);
			break;
		}
	}

	if ("1" == response)
		return AvailableCommands::Exit;

	else if ("2" == response)
		return AvailableCommands::GetCardFromDeck;

	return AvailableCommands::GetCardFromGarbage;
}

std::string Command::GetCardResponse(Board* board, Card newCard)
{
	std::vector<std::string> availableOptions = {"0", "1", "2", "3", "4", "5"};
	std::string response;

	auto playerTurn = board->getPlayerTurn();
	auto player = board->getPlayers()[playerTurn];

	if (!player.isComputer())
	{
		while (true)
		{
			Display::CardPrompt(player);
			response = Display::GetInput();

			if (1 > std::count(availableOptions.begin(), availableOptions.end(), response))
				Display::CommandError("ERROR: CARD NUMBER '", response);
			else
				break;
		}
	}
	else
	{
		response = board->getComputerResponse(ComputerResponses::CardResponse, newCard);
	}

	return response;
}