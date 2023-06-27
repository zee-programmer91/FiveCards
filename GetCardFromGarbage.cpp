#include "GetCardFromGarbage.h"
#include "Command.h"

#include <iostream>

bool GetCardFromGarbage::execute(Board* board)
{
	if (board->isGarbageEmpty())
		Command::garbageEmptyMessage();
	return true;
}