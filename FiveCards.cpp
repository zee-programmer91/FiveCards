#include "Card.h"
#include "Deck.h"
#include "Tests.h"

#include <iostream>
#include <set>

int main()
{

	if (Tests::runTests())
	{
		Deck deck{};

		for (int count = 1; count <= 52; count++)
		{
			auto card = deck.getNextCard();
			std::cout << "Value: " << card.getCardValue() << "\n";
			std::cout << "Type: "  << card.getCardType()  << "\n\n";
		}
	}
}
