#pragma once
#include "Card.h"

#include <vector>

class Garbage
{
	public:
		void disposeCard(Card card);
		bool empty();
		Card retrieveLastDisposedCard();
		Card retrieveTopcard();
	protected:
		std::vector<Card> disposedCards{};
};