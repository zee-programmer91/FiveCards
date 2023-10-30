#include "Deck.h"

Deck::Deck()
{
	shuffleDeck();
}

std::array<Card, 52> Deck::getAllDeckCards()
{
	return deckCards;
}

void Deck::shuffleDeck()
{
	// IMPORTANT: Use current time as seed for random generator (or rand() won't generate at random)
	srand(time(0));
	while (52 != randomIndices.size())
	{
		int randomNumber = rand() % 52;
		if(0 == std::count(randomIndices.begin(), randomIndices.end(), randomNumber))
		{
			randomIndices.push_back(randomNumber);
		}
	}
}

Card Deck::getNextCard()
{
	if (randomIndices.empty())
		shuffleDeck();

	auto index = randomIndices.begin();
	auto nextCard = deckCards[*index];

	randomIndices.erase(randomIndices.begin());

	return nextCard;
}