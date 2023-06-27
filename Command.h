#pragma once
#include "Board.h"
#include "Structs.h"

#include <iostream>
#include <string>
#include <vector>

class Command
{
	public:
		static void GarbageEmptyMessage();
		static std::string GetInput();
		static AvailableCommands GetUserCommand(Board* board);
		static std::string GetCardResponse();

		template<typename CommandType>
		static bool HandleRequest(Board* board)
		{	
			CommandType command{};
			return command.execute(board);
		};
	protected:
		std::string name;
};