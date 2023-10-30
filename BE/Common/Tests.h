#pragma once
#include "../Components/Card/Card.h"
#include "../Components/Command/Command.h"
#include "../Components/Deck/Deck.h"
#include "../Components/GetCardFrom/Sub/GetCardFromDeck/GetCardFromDeck.h"
#include "../Components/GetCardFrom/Sub/GetCardFromGarbage/GetCardFromGarbage.h"
#include "../Common/Helper.h"
#include "../Components/Player/Player.h"

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