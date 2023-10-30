#pragma once
#include "../../../Board/Board.h"

#include <string>

class GetCardFromGarbage
{
	public:
		std::string name = "GetCardFromGarbage";
		bool execute(Board* board);
};