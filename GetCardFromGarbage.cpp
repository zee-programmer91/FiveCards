#include "GetCardFromGarbage.h"
#include "Command.h"
#include "GetCardFrom.h"

#include <iostream>

bool GetCardFromGarbage::execute(Board* board)
{
	if (board->isGarbageEmpty())
	{
		Command::GarbageEmptyMessage();
	}
	else
	{
		GetFrom::ProcessFromContainer(board, AvailableCommands::GetCardFromGarbage);
	}
	return true;
}