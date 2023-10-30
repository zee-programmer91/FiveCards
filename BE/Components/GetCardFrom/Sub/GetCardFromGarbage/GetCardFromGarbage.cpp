#include "GetCardFromGarbage.h"
#include "../../../Command/Command.h"
#include "../../../Display/Display.h"
#include "../../GetCardFrom.h"

bool GetCardFromGarbage::execute(Board* board)
{
	if (board->isGarbageEmpty())
	{
		Display::GarbageEmptyMessage();
		board->changePlayer = false;
	}
	else
	{
		GetCardFrom::ProcessFromContainer(board, AvailableCommands::GetCardFromGarbage);
		board->changePlayer = true;
	}
	return true;
}