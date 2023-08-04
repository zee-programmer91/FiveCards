#include "Display.h"
#include "FiveCardsEngine.h"
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
		Board* boardPtr = &board;
		Display::DisplayTitle("WELCOME TO FIVE CARDS GAME");

		while (continueGame)
		{
			continueGame = FiveCardsEngine::runGame(boardPtr);

			if (boardPtr->getPlayer().isComputer())
				Display::NormalMessage("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

			if (continueGame)
			{
				auto winner = boardPtr->checkWinner();

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