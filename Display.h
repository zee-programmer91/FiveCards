#pragma once
#include "Board.h"
#include "Player.h"

#include <iostream>
#include <map>

class Display
{
	public:
		static void CardPrompt();
		static void CommandError(std::string errorMessage, std::string userResponse);
		static void CommandPrompt();
		static void ComputerTurn();
		static void DisplayTitle(std::string title);
		static void DisposedCardMessage(Player player, Board* board, Card card);
		static void GarbageEmptyMessage();
		static std::string GetInput();
		static void NormalMessage(std::string message);
		static void WinningCards(std::map<std::string, int> cardsCount);
};