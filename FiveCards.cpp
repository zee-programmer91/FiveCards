#include "Board.h"
#include "Card.h"
#include "Deck.h"
#include "Exit.h"
#include "GetCardFromDeck.h"
#include "GetCardFromGarbage.h"
#include "Player.h"
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

		std::cout << "\n						############################\n";
		std::cout << "						 WELCOME TO FIVE CARDS GAME\n";
		std::cout << "						############################\n\n";

		while (continueGame)
		{
			auto request = Command::getUserRequest(board);

			if (request == AvailableCommands::Exit)
			{
				continueGame = Command::handleRequest<Exit>();
			}

			else if (request == AvailableCommands::GetCardFromDeck)
			{
				continueGame = Command::handleRequest<GetCardFromDeck>();
			}

			else if (request == AvailableCommands::GetCardFromGarbage)
			{
				continueGame = Command::handleRequest<GetCardFromGarbage>();
			}
		}
	}
}