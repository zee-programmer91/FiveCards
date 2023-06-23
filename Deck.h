#pragma once

#include "Card.h"
#include "Garbage.h"

#include <array>
#include <vector>

class Deck
{
	public:
		Deck();
		Card getNextCard();
	private:
		std::vector<int> randomIndices{};
		const std::array<Card, 52> deckCards
		{
			{
				Card{"A", "C"}, Card{"A", "D"}, Card{"A", "H"}, Card{"A", "S"},
				Card{"2", "C"}, Card{"2", "D"}, Card{"2", "H"}, Card{"2", "S"},
				Card{"3", "C"}, Card{"3", "D"}, Card{"3", "H"}, Card{"3", "S"},
				Card{"4", "C"}, Card{"4", "D"}, Card{"4", "H"}, Card{"4", "S"},
				Card{"5", "C"}, Card{"5", "D"}, Card{"5", "H"}, Card{"5", "S"},
				Card{"6", "C"}, Card{"6", "D"}, Card{"6", "H"}, Card{"6", "S"},
				Card{"7", "C"}, Card{"7", "D"}, Card{"7", "H"}, Card{"7", "S"},
				Card{"8", "C"}, Card{"8", "D"}, Card{"8", "H"}, Card{"8", "S"},
				Card{"9", "C"}, Card{"9", "D"}, Card{"9", "H"}, Card{"9", "S"},
				Card{"10", "C"}, Card{"10", "D"}, Card{"10", "H"}, Card{"10", "S"},
				Card{"J", "C"}, Card{"J", "D"}, Card{"J", "H"}, Card{"J", "S"},
				Card{"Q", "C"}, Card{"Q", "D"}, Card{"Q", "H"}, Card{"Q", "S"},
				Card{"K", "C"}, Card{"K", "D"}, Card{"K", "H"}, Card{"K", "S"},
			}
		};
		void shuffleDeck();
};
