#pragma once
#include "Card.h"

#include <array>

class Player
{
	public:
		void setCard(int position, Card newCard);
		Card getCard(int position);
	private:
		std::array<Card, 5> cards = {
			Card{"E", CardTypes::empty},
			Card{"E", CardTypes::empty},
			Card{"E", CardTypes::empty},
			Card{"E", CardTypes::empty},
			Card{"E", CardTypes::empty},
		};
};