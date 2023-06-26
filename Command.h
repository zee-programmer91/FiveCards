#pragma once
#include "Board.h"
#include "Structs.h"

#include <iostream>
#include <string>
#include <vector>

class Command
{
	public:
		Command(std::string instruction);
		std::string getCommandName();
		bool execute();
		static AvailableCommands getUserRequest(Board* board);

		template<typename CommandType>
		static bool handleRequest(Board* board)
		{	
			CommandType command{};
			return command.execute(board);
		};
	protected:
		std::string name;
};