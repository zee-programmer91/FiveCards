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
	while (52 != randomIndices.size())
	{
		int randomNumber = rand() % 52;
		randomIndices.insert(randomNumber);
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