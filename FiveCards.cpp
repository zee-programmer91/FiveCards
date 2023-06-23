#include "Card.h"
#include "Deck.h"
#include "Tests.h"

#include <iostream>
#include <set>

int main()
{
	std::set<std::string> mySet{};

	if (Tests::runTests())
	{
		Deck deck{};

		for (int count = 1; count <= 52; count++)
		{
			auto card = deck.getNextCard();
			std::cout << "Value: " << card.getCardValue() << "\n";
			std::cout << "Type: "  << card.getCardType()  << "\n\n";
			mySet.insert(card.getCardValue()+card.getCardType());
		}
	}

	std::cout << "Program Ended! count: "<< mySet.size() <<"\n";
}
