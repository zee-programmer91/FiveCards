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
		static bool runTests();
	private:
		static bool testCard();
		static bool testDeck();
		static bool testHelper();
		static bool testPlayer();
};