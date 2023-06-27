#include "Board.h"
#include "Tests.h"

#include <iostream>
#include <set>

int main()
{

	if (Tests::RunTests())
	{
		auto continueGame = true;
		Deck deck{};
		Garbage garbage{};
		Player player1{};
		Player player2{};
		std::vector<Player> players{ player1 , player2};

		Board board{ "Board.txt", players, deck, garbage };
		board.displayTitle();

		while (continueGame)
		{
			continueGame = board.runGame();
		}
	}
}