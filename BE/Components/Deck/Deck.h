#pragma once

#include "../Card/Card.h"
#include "../Garbage/Garbage.h"

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
				Card{"A", CardTypes::Clubs}, Card{"A", CardTypes::Diamonds}, Card{"A", CardTypes::Hearts}, Card{"A", CardTypes::Spades},
				Card{"2", CardTypes::Clubs}, Card{"2", CardTypes::Diamonds}, Card{"2", CardTypes::Hearts}, Card{"2", CardTypes::Spades},
				Card{"3", CardTypes::Clubs}, Card{"3", CardTypes::Diamonds}, Card{"3", CardTypes::Hearts}, Card{"3", CardTypes::Spades},
				Card{"4", CardTypes::Clubs}, Card{"4", CardTypes::Diamonds}, Card{"4", CardTypes::Hearts}, Card{"4", CardTypes::Spades},
				Card{"5", CardTypes::Clubs}, Card{"5", CardTypes::Diamonds}, Card{"5", CardTypes::Hearts}, Card{"5", CardTypes::Spades},
				Card{"6", CardTypes::Clubs}, Card{"6", CardTypes::Diamonds}, Card{"6", CardTypes::Hearts}, Card{"6", CardTypes::Spades},
				Card{"7", CardTypes::Clubs}, Card{"7", CardTypes::Diamonds}, Card{"7", CardTypes::Hearts}, Card{"7", CardTypes::Spades},
				Card{"8", CardTypes::Clubs}, Card{"8", CardTypes::Diamonds}, Card{"8", CardTypes::Hearts}, Card{"8", CardTypes::Spades},
				Card{"9", CardTypes::Clubs}, Card{"9", CardTypes::Diamonds}, Card{"9", CardTypes::Hearts}, Card{"9", CardTypes::Spades},
				Card{"10", CardTypes::Clubs}, Card{"10", CardTypes::Diamonds}, Card{"10", CardTypes::Hearts}, Card{"10", CardTypes::Spades},
				Card{"J", CardTypes::Clubs}, Card{"J", CardTypes::Diamonds}, Card{"J", CardTypes::Hearts}, Card{"J", CardTypes::Spades},
				Card{"Q", CardTypes::Clubs}, Card{"Q", CardTypes::Diamonds}, Card{"Q", CardTypes::Hearts}, Card{"Q", CardTypes::Spades},
				Card{"K", CardTypes::Clubs}, Card{"K", CardTypes::Diamonds}, Card{"K", CardTypes::Hearts}, Card{"K", CardTypes::Spades},
			}
		};
		void shuffleDeck();
};