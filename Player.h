#pragma once
#include "Card.h"

#include <array>

class Player
{
	public:
		Player(bool computerPlayer = false);
		void setCard(int position, Card newCard);
		Card getCard(int position);
		std::array<Card, 5> getPlayerCards();
		bool isComputer();
	private:
		bool computerPlayer;
		std::array<Card, 5> cards = {
			Card{"E", CardTypes::Empty},
			Card{"E", CardTypes::Empty},
			Card{"E", CardTypes::Empty},
			Card{"E", CardTypes::Empty},
			Card{"E", CardTypes::Empty},
		};
};