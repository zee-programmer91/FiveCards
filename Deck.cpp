#include "Deck.h"

Deck::Deck()
{
	shuffleDeck();
}

void Deck::shuffleDeck()
{
	while (52 != randomIndices.size())
	{
		int randomNumber = rand() % 52;

		if (std::count(randomIndices.begin(), randomIndices.end(), randomNumber))
			continue;

		randomIndices.push_back(randomNumber);
	}
}

Card Deck::getNextCard()
{
	if (randomIndices.empty())
		shuffleDeck();

	auto index = randomIndices.front();
	auto nextCard = deckCards[index];

	randomIndices.erase(randomIndices.begin());

	return nextCard;
}