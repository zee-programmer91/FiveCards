#include "Board.h"
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Tests.h"

#include <iostream>
#include <set>

int main()
{

	if (Tests::runTests())
	{
		Deck deck{};
		Player player1{};
		Player player2{};
		std::vector<Player> players{ player1 , player2};

		Board board{ "Board.txt", players };
		board.displayBoard();
	}
}