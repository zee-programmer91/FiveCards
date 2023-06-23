#include "Board.h"
#include "Card.h"
#include "Deck.h"
#include "Tests.h"

#include <iostream>
#include <set>

int main()
{

	if (Tests::runTests())
	{
		Board board{"Board.txt"};

		board.displayBoard();
	}
}