#include "Command.h"

void Command::GarbageEmptyMessage()
{
	std::cout << "Sorry, garbage is currently empty!\nTry pick card from Deck\n";
}

AvailableCommands Command::GetUserCommand(Board* board)
{
	std::string response;

	while (true)
	{
		board->displayBoard();
		std::cout << "\nWhat do you want to do?\n";
		std::cout << "1 - Exit\n";
		std::cout << "2 - Get Card From Deck\n";
		std::cout << "3 - Get Card from Garbage\n";

		response = GetInput();

		if ("1" != response && "2" != response && "3" != response)
			std::cout << "ERROR: COMMNAND '" << response << "' DOES NOT EXIST.\nTRY AGAIN\n";
		else
			break;
	}

	if ("1" == response)
		return AvailableCommands::Exit;

	else if ("2" == response)
		return AvailableCommands::GetCardFromDeck;

	return AvailableCommands::GetCardFromGarbage;
}

std::string Command::GetInput()
{
	std::string response;
	std::cout << "\n>> ";
	std::cin >> response;
	std::cout << "\n";

	return response;
}

std::string Command::GetCardResponse()
{
	std::vector<std::string> availableOptions = {"0", "1", "2", "3", "4", "5"};
	std::string response;
	while (true)
	{
		std::cout << "Which card do you want to replaced?\n";
		std::cout << "0 - Discard Picked Card\n";
		std::cout << "1 - Card 1\n";
		std::cout << "2 - Card 2\n";
		std::cout << "3 - Card 3\n";
		std::cout << "4 - Card 4\n";
		std::cout << "5 - Card 5\n";

		response = GetInput();

		if (1 > std::count(availableOptions.begin(), availableOptions.end(), response))
			std::cout << "ERROR: CARD NUMBER '" << response << "' DOES NOT EXIST.\nTRY AGAIN\n\n";
		else
			break;
	}

	return response;
}