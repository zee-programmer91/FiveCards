#pragma once

#include "Card.h"
#include "Garbage.h"

#include <array>
#include <set>
#include <time.h>
#include <vector>

class Deck
{
	public:
		Deck();
		Card getNextCard();
		std::array<Card, 52> getAllDeckCards();
	private:
		std::vector<int> randomIndices{};
		const std::array<Card, 52> deckCards
		{
			{
				Card{"A", CardTypes::clubs}, Card{"A", CardTypes::diamonds}, Card{"A", CardTypes::hearts}, Card{"A", CardTypes::spades},
				Card{"2", CardTypes::clubs}, Card{"2", CardTypes::diamonds}, Card{"2", CardTypes::hearts}, Card{"2", CardTypes::spades},
				Card{"3", CardTypes::clubs}, Card{"3", CardTypes::diamonds}, Card{"3", CardTypes::hearts}, Card{"3", CardTypes::spades},
				Card{"4", CardTypes::clubs}, Card{"4", CardTypes::diamonds}, Card{"4", CardTypes::hearts}, Card{"4", CardTypes::spades},
				Card{"5", CardTypes::clubs}, Card{"5", CardTypes::diamonds}, Card{"5", CardTypes::hearts}, Card{"5", CardTypes::spades},
				Card{"6", CardTypes::clubs}, Card{"6", CardTypes::diamonds}, Card{"6", CardTypes::hearts}, Card{"6", CardTypes::spades},
				Card{"7", CardTypes::clubs}, Card{"7", CardTypes::diamonds}, Card{"7", CardTypes::hearts}, Card{"7", CardTypes::spades},
				Card{"8", CardTypes::clubs}, Card{"8", CardTypes::diamonds}, Card{"8", CardTypes::hearts}, Card{"8", CardTypes::spades},
				Card{"9", CardTypes::clubs}, Card{"9", CardTypes::diamonds}, Card{"9", CardTypes::hearts}, Card{"9", CardTypes::spades},
				Card{"10", CardTypes::clubs}, Card{"10", CardTypes::diamonds}, Card{"10", CardTypes::hearts}, Card{"10", CardTypes::spades},
				Card{"J", CardTypes::clubs}, Card{"J", CardTypes::diamonds}, Card{"J", CardTypes::hearts}, Card{"J", CardTypes::spades},
				Card{"Q", CardTypes::clubs}, Card{"Q", CardTypes::diamonds}, Card{"Q", CardTypes::hearts}, Card{"Q", CardTypes::spades},
				Card{"K", CardTypes::clubs}, Card{"K", CardTypes::diamonds}, Card{"K", CardTypes::hearts}, Card{"K", CardTypes::spades},
			}
		};
		void shuffleDeck();
};