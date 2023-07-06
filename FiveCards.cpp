#include "Display.h"
#include "Tests.h"

int main()
{

	if (Tests::RunTests())
	{
		auto continueGame = true;
		Deck deck{};
		Garbage garbage{};
		Player player1{ true };
		Player player2{};
		std::vector<Player> players{ player1 , player2};

		Board board{ "Board.txt", players, deck, garbage };
		Display::DisplayTitle("WELCOME TO FIVE CARDS GAME");

		while (continueGame)
		{
			continueGame = board.runGame();

			if (board.getPlayer().isComputer())
				Display::NormalMessage("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

			if (continueGame)
			{
				auto winner = board.checkWinner();

				if (winner == Winner::Player1Wins || winner == Winner::Player2Wins)
				{
					if (winner == Winner::Player1Wins)
					{
						std::cout << "\nComputer won the game!!\n";
						break;
					}
					std::cout << "\nPlayer won the game!!\n";
					break;
				}
			}
		}
	}
}