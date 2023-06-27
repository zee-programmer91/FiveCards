#include "Garbage.h"

void Garbage::disposeCard(Card card)
{
	disposedCards.push_back(card);
}

Card Garbage::retrieveLastDisposedCard()
{
	auto card = disposedCards.back();
	disposedCards.erase(disposedCards.end());

	return card;
}