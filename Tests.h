#pragma once
#include "Card.h"
#include "Deck.h"
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
		static bool testPlayer();
};