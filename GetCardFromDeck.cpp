#include "GetCardFromDeck.h"
#include "Command.h"
#include "GetCardFrom.h"

#include <iostream>

bool GetCardFromDeck::execute(Board* board)
{
	GetFrom::ProcessFromContainer(board, AvailableCommands::GetCardFromDeck);

	return true;
}