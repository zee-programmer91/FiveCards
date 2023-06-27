#pragma once
#include "Board.h"
#include "Structs.h"

#include <iostream>
#include <string>
#include <vector>

class Command
{
	public:
		static void garbageEmptyMessage();
		static std::string getInput();
		static AvailableCommands getUserCommand(Board* board);
		static std::string getCardResponse();

		template<typename CommandType>
		static bool handleRequest(Board* board)
		{	
			CommandType command{};
			return command.execute(board);
		};
	protected:
		std::string name;
};