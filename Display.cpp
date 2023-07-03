#include "Display.h"

void Display::CardPrompt()
{
	std::cout << "Which card do you want to replaced?\n";
	std::cout << "0 - Discard Picked Card\n";
	std::cout << "1 - Card 1\n";
	std::cout << "2 - Card 2\n";
	std::cout << "3 - Card 3\n";
	std::cout << "4 - Card 4\n";
	std::cout << "5 - Card 5\n";
}

void Display::CommandError(std::string errorMessage, std::string userResponse)
{
	std::cout << errorMessage << userResponse << "' DOES NOT EXIST.\nTRY AGAIN\n\n";
}

void Display::CommandPrompt()
{
	std::cout << "\nWhat do you want to do?\n";
	std::cout << "1 - Exit\n";
	std::cout << "2 - Get Card From Deck\n";
	std::cout << "3 - Get Card from Garbage\n";
}

void Display::ComputerTurn()
{
	std::cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++\nComputer turn\n"
		<< "++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
}

void Display::DisplayTitle(std::string title)
{
	std::cout << "\n						############################\n";
	std::cout << "						 " << title << "\n";
	std::cout << "						############################\n\n";
}

void Display::DisposedCardMessage(Player player, Board* board, Card card)
{
	if (!player.isComputer())
		std::cout << "--> Player " << (board->getPlayerTurn() + 1) << " disposed the following card: " << card.getCardInfor() << "\n";
	else
		std::cout << "--> Computer " << (board->getPlayerTurn() + 1) << " disposed the following card: " << card.getCardInfor() << "\n";
}

void Display::GarbageEmptyMessage()
{
	std::cout << "Sorry, garbage is currently empty!\nTry pick card from Deck\n";
}

std::string Display::GetInput()
{
	std::string response;
	std::cout << "\n>> ";
	std::cin >> response;
	std::cout << "\n";

	return response;
}

void Display::NormalMessage(std::string message)
{
	std::cout << message;
}

void Display::WinningCards(std::map<std::string, int> cardsCount)
{
	std::cout << "\nWinning Cards:\n--------------\n";
	for (auto cardCount : cardsCount)
	{
		std::cout << "Value: " << cardCount.first;
		std::cout << " --> Count: " << cardCount.second << "\n";
	}
}