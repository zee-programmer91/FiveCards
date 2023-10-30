#include "GetCardFromDeck.h"
#include "../../../Command/Command.h"
#include "../../GetCardFrom.h"

#include <iostream>

bool GetCardFromDeck::execute(Board* board)
{
	GetCardFrom::ProcessFromContainer(board, AvailableCommands::GetCardFromDeck);
	board->changePlayer = true;

	return true;
}