#pragma once
#include "Board.h"

#include <string>

class GetCardFromDeck
{
	public:
		std::string name = "GetCardFromDeck";
		bool execute(Board* board);
};