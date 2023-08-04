#pragma once
#include "Board.h"
#include "Command.h"
#include "Exit.h"
#include "GameEngine.cpp"
#include "GetCardFromDeck.h"
#include "GetCardFromGarbage.h"

class FiveCardsEngine : public GameEngine
{
	public:
		static bool runGame(Board* board);
};