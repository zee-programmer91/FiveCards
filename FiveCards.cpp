#include "Board.h"
#include "Tests.h"

#include <iostream>
#include <set>

int main()
{

	if (Tests::runTests())
	{
		auto continueGame = true;
		Deck deck{};
		Player player1{};
		Player player2{};
		std::vector<Player> players{ player1 , player2};

		Board board{ "Board.txt", players, deck };
		board.displayTitle();

		while (continueGame)
		{
			continueGame = board.runGame();
		}
	}
}