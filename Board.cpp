#include "Board.h"

Board::Board(std::string filePath, std::vector<Player>& newPlayers) : players(newPlayers)
{
	interfaceFile.open(filePath);
	readFromFile();
}

Board::~Board()
{
	interfaceFile.close();
}

void Board::displayBoard()
{
	refreshBoard();
	for (const auto row : boardInterface)
	{
		for (const auto value : row)
			std::cout << value;

		std::cout << "\n";
	}
}

void Board::readFromFile()
{
	std::string row{};
	while (!interfaceFile.eof())
	{
		std::getline(interfaceFile, row);
		std::vector<std::string> boardRow{};

		for (auto value : row)
			boardRow.push_back(std::string{ value });
		boardInterface.push_back(boardRow);
	}
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
	for (auto availablePlayer : availablePlayers)
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
}