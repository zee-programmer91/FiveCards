#pragma once
#include "Board.h"

#include <string>

class Exit
{
	public:
		std::string name = "Exit";
		bool execute(Board* board);
};