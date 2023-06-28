#include "Board.h"
#include "Command.h"
#include "Exit.h"
#include "GetCardFromDeck.h"
#include "GetCardFromGarbage.h"

Board::Board(std::string filePath, std::vector<Player>& newPlayers, Deck& newDeck, Garbage newGarbage)
	: players(newPlayers), deck(newDeck), garbage(newGarbage)
{
	interfaceFile.open(filePath);
	readFromFile();
	initializePlayerCards();
}

Board::~Board()
{
	interfaceFile.close();
}

Winner Board::checkWinner()
{
	auto winner = Winner::None;
	auto player = players[playerTurn];

	//	map to save repeating cards
	std::map<std::string, int> cardsCount{};

	for (auto card : player.getPlayerCards())
	{
		if (cardsCount.find(card.getCardValue()) == cardsCount.end())
		{
			cardsCount[card.getCardValue()] = 1;
		}
		else
		{
			auto& count = cardsCount[card.getCardValue()];
			count++;
		}

	}

	if (2 == cardsCount.size())
	{
		std::cout << "\nWinning Cards:\n--------------\n";
		for (auto cardCount : cardsCount)
		{
			std::cout << "Value: " << cardCount.first;
			std::cout << " --> Count: " << cardCount.second << "\n";
		}
		winner = 0 == playerTurn ? Winner::Player1 : Winner::Player2;
	}
	else
	{
		std::cout << "Cards Count:\n------------\n";
		for (auto cardCount : cardsCount)
		{
			std::cout << "Value: " << cardCount.first;
			std::cout << " --> Count: " << cardCount.second << "\n";
		}
	}

	return winner;
}

void Board::initializePlayerCards()
{
	for (auto& player : players)
	{
		player.setCard(1, deck.getNextCard());
		player.setCard(2, deck.getNextCard());
		player.setCard(3, deck.getNextCard());
		player.setCard(4, deck.getNextCard());
		player.setCard(5, deck.getNextCard());
	}
}

void Board::displayBoard()
{
	refreshBoard();
	std::cout << "\n";
	for (const auto row : boardInterface)
	{
		for (const auto value : row)
			std::cout << value;

		std::cout << "\n";
	}
}

void Board::displayTitle()
{
	std::cout << "\n						############################\n";
	std::cout << "						 WELCOME TO FIVE CARDS GAME\n";
	std::cout << "						############################\n\n";
}

void Board::disposeDiscardedCard(Card card)
{
	garbage.disposeCard(card);
}

Card Board::getCardFromDeck()
{
	return deck.getNextCard();
}

Card Board::getCardFromGarbage()
{
	return garbage.retrieveLastDisposedCard();
}

Player& Board::getPlayer()
{
	if (0 == playerTurn)
		playerTurn = players.size();
	playerTurn--;

	return players[playerTurn];
}

int Board::getPlayerTurn()
{
	return playerTurn;
}

bool Board::isGarbageEmpty()
{
	return garbage.empty();
}

void Board::processRequest(Player& player, const Card newCard, std::string& response)
{
	if ("0" == response)
	{
		disposeDiscardedCard(newCard);
	}
	else
	{
		auto cardNumber = CardNumber::ONE;

		if ("2" == response)
			cardNumber = CardNumber::TWO;
		if ("3" == response)
			cardNumber = CardNumber::THREE;
		if ("4" == response)
			cardNumber = CardNumber::FOUR;
		if ("5" == response)
			cardNumber = CardNumber::FIVE;

		auto playerCard = player.getCard(cardNumber);
		disposeDiscardedCard(playerCard);
		player.setCard(cardNumber, newCard);
	}
}

void Board::readFromFile()
{
	std::string row{};
	while (!interfaceFile.eof())
	{
		std::getline(interfaceFile, row);
		std::vector<std::string> boardRow{};

		for (const auto value : row)
			boardRow.push_back(std::string{ value });
		boardInterface.push_back(boardRow);
	}
}

bool Board::runGame()
{
	auto request = Command::GetUserCommand(this);

	if (request == AvailableCommands::Exit)
	{
		return Command::HandleRequest<Exit>(this);
	}

	else if (request == AvailableCommands::GetCardFromDeck)
	{
		return Command::HandleRequest<GetCardFromDeck>(this);
	}

	return Command::HandleRequest<GetCardFromGarbage>(this);
}

void Board::refreshBoard()
{
	std::vector<PlayerRow> availablePlayers = { PlayerRow::player1 , PlayerRow::player2 };

	auto card1Value = CardPositions::card1;
	auto card1Type = CardPositions::card1 + 1;
	auto card2Value = CardPositions::card2;
	auto card2Type = CardPositions::card2 + 1;
	auto card3Value = CardPositions::card3;
	auto card3Type = CardPositions::card3 + 1;
	auto card4Value = CardPositions::card4;
	auto card4Type = CardPositions::card4 + 1;
	auto card5Value = CardPositions::card5;
	auto card5Type = CardPositions::card5 + 1;

	int count = 0;
	for (const auto availablePlayer : availablePlayers)
	{
		boardInterface[availablePlayer][card1Value] = players[count].getCard(1).getCardValue();
		boardInterface[availablePlayer][card1Type] = players[count].getCard(1).getCardType();
		boardInterface[availablePlayer][card2Value] = players[count].getCard(2).getCardValue();
		boardInterface[availablePlayer][card2Type] = players[count].getCard(2).getCardType();
		boardInterface[availablePlayer][card3Value] = players[count].getCard(3).getCardValue();
		boardInterface[availablePlayer][card3Type] = players[count].getCard(3).getCardType();
		boardInterface[availablePlayer][card4Value] = players[count].getCard(4).getCardValue();
		boardInterface[availablePlayer][card4Type] = players[count].getCard(4).getCardType();
		boardInterface[availablePlayer][card5Value] = players[count].getCard(5).getCardValue();
		boardInterface[availablePlayer][card5Type] = players[count].getCard(5).getCardType();
		count++;
	}

	if (!garbage.empty())
	{
		auto card = garbage.retrieveTopcard();
		boardInterface[GarbagePosition::G_row][GarbagePosition::leftPosition] = card.getCardValue();
		boardInterface[GarbagePosition::G_row][GarbagePosition::rightPosition] = card.getCardType();
	}
}