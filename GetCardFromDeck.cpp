#include "GetCardFromDeck.h"
#include "Command.h"
#include "GetCardFrom.h"

#include <iostream>

bool GetCardFromDeck::execute(Board* board)
{
	GetCardFrom::ProcessFromContainer(board, AvailableCommands::GetCardFromDeck);

	return true;
}