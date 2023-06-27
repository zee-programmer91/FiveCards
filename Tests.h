#pragma once
#include "Card.h"
#include "Command.h"
#include "Deck.h"
#include "GetCardFromDeck.h"
#include "GetCardFromGarbage.h"
#include "Helper.h"
#include "Player.h"

#include <iostream>
#include <set>

class Tests
{
	public:
		static bool RunTests();
	private:
		static bool TestCard();
		static bool TestDeck();
		static bool TestHelper();
		static bool TestPlayer();
};