#include "Command.h"
#include "GetCardFromDeck.h"
#include "GetCardFromGarbage.h"

Command::Command(std::string command): name(command){}

Command Command::createCommand(std::string command)
{
	if ("GetCardFromDeck" == command)
		return GetCardFromDeck(command);

	if ("GetCardFromGarbage" == command)
		return GetCardFromGarbage(command);
	else
		return Command("");
}

std::string Command::getCommandName()
{
	return name;
}
