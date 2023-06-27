#pragma once
#include "Card.h"

#include <vector>

class Garbage
{
	public:
		void disposeCard(Card card);
		Card retrieveLastDisposedCard();
	protected:
		std::vector<Card> disposedCards{};
};