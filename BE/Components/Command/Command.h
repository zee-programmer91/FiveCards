#pragma once
#include "../Board/Board.h"
#include "../../Common/Structs.h"

#include <iostream>
#include <string>
#include <vector>

class Command
{
	public:
		static AvailableCommands GetUserCommand(Board* board);
		static std::string GetCardResponse(Board* board, Card newCard);

		template<typename CommandType>
		static bool HandleRequest(Board* board)
		{	
			CommandType command{};
			return command.execute(board);
		};
	protected:
		std::string name;
};