#include "Garbage.h"

void Garbage::disposeCard(Card card)
{
	disposedCards.push_back(card);
}

bool Garbage::empty()
{
	return disposedCards.empty();
}

Card Garbage::retrieveLastDisposedCard()
{
	auto card = disposedCards.back();
	disposedCards.erase(disposedCards.end());

	return card;
}

Card Garbage::retrieveTopcard()
{
	return disposedCards.back();
}