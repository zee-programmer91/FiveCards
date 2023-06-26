#include "Command.h"

Command::Command(std::string command): name(command){}

std::string Command::getCommandName()
{
	return name;
}

AvailableCommands Command::getUserRequest(Board* board)
{
	std::string response;

	while (true)
	{
		board->displayBoard();
		std::cout << "\nWhat do you want to do?\n";
		std::cout << "1 - Exit\n";
		std::cout << "2 - Get Card From Deck\n";
		std::cout << "3 - Get Card from Garbage\n\n>> ";
		std::cin >> response;

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

bool Command::execute()
{
	return false;
}