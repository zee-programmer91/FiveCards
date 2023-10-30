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
	if (!disposedCards.empty())
	{
		disposedCards.erase(disposedCards.end()-1);
	}

	return card;
}

Card Garbage::retrieveTopcard()
{
	return disposedCards.back();
}