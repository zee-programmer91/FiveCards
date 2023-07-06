#include "Board.h"
#include "Command.h"
#include "Display.h"
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

	//	map to save repeating cards
	auto cardsCount = countPlayerCards(Processes::CheckWinner);

	if (2 == cardsCount.size())
	{
		winner = 0 == playerTurn ? Winner::Player1Wins : Winner::Player2Wins;
		std::array<Card, 5> cards;

		if (Winner::Player1Wins == winner)
			cards = players[0].getPlayerCards();
		else if (Winner::Player2Wins == winner)
			cards = players[1].getPlayerCards();
			
		Display::WinningCards(cards);
	}

	return winner;
}

void Board::changePlayerTurn()
{
	if (0 == playerTurn)
		playerTurn = players.size();
	playerTurn--;
}

std::map<std::string, int> Board::countPlayerCards(Processes process)
{
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

	return cardsCount;
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
	Display::NormalMessage("\n");
	for (const auto row : boardInterface)
	{
		for (const auto value : row)
			Display::NormalMessage(value);

		Display::NormalMessage("\n");
	}
}

void Board::disposeDiscardedCard(Card card)
{
	garbage.disposeCard(card);
}

Card Board::getCardFromDeck()
{
	return deck.getNextCard();
}

Card Board::getCardFromGarbage(GarbageOptions option)
{
	if (option == GarbageOptions::RetrieveCard)
	{
		return garbage.retrieveLastDisposedCard();
	}
	return garbage.retrieveTopcard();
}

Player& Board::getPlayer()
{
	return players[playerTurn];
}

int Board::getPlayerTurn()
{
	return playerTurn;
}

std::string Board::getComputerResponse(ComputerResponses response, Card newCard)
{
	std::map<int, std::string> possibleResponses = {
		{1, "1"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}
	};

	auto cardsCount = countPlayerCards(Processes::CheckComputerCards);

	switch (response)
	{
		case CommandResponse:
			for (auto nextCardCount : cardsCount)
			{
				auto card = getCardFromGarbage(GarbageOptions::RetrieveCardInfor);
				switch (nextCardCount.second)
				{
				case 1:
				case 2:
					if (card.getCardValue() == nextCardCount.first)
						return possibleResponses.find((int)AvailableCommands::GetCardFromGarbage)->second;
					break;
				case 3:
					continue;
				}
			}

			return possibleResponses.find((int)AvailableCommands::GetCardFromDeck)->second;
		case CardResponse:
			std::string cardNumber;

			for (auto nextCardCount : cardsCount)
			{
				if (1 == nextCardCount.second && newCard.getCardValue() != nextCardCount.first)
				{
					cardNumber = nextCardCount.first;
					break;
				}
			}

			auto computerCards = getPlayer().getPlayerCards();
			auto cardCount = 1;

			for (auto card : computerCards)
			{
				if (card.getCardValue() == cardNumber)
					break;
				cardCount++;
			}

			return possibleResponses[cardCount];
	}

	return possibleResponses.find((int)AvailableCommands::Exit)->second;
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

		Display::DisposedCardMessage(player, this, playerCard);
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
	std::vector<PlayerRow> availablePlayers = { PlayerRow::Player1Row , PlayerRow::Player2Row };

	auto card1Value = CardPositions::Card1;
	auto card1Type = CardPositions::Card1 + 1;
	auto card2Value = CardPositions::Card2;
	auto card2Type = CardPositions::Card2 + 1;
	auto card3Value = CardPositions::Card3;
	auto card3Type = CardPositions::Card3 + 1;
	auto card4Value = CardPositions::Card4;
	auto card4Type = CardPositions::Card4 + 1;
	auto card5Value = CardPositions::Card5;
	auto card5Type = CardPositions::Card5 + 1;

	int count = 0;
	auto computerValue = "#";
	for (const auto availablePlayer : availablePlayers)
	{
		switch (availablePlayer)
		{
			case Player1Row:
				boardInterface[availablePlayer][card1Value] = computerValue;
				boardInterface[availablePlayer][card1Type] = computerValue;
				boardInterface[availablePlayer][card2Value] = computerValue;
				boardInterface[availablePlayer][card2Type] = computerValue;
				boardInterface[availablePlayer][card3Value] = computerValue;
				boardInterface[availablePlayer][card3Type] = computerValue;
				boardInterface[availablePlayer][card4Value] = computerValue;
				boardInterface[availablePlayer][card4Type] = computerValue;
				boardInterface[availablePlayer][card5Value] = computerValue;
				boardInterface[availablePlayer][card5Type] = computerValue;
				break;
			case Player2Row:
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
				break;
		}
		count++;
	}

	if (!garbage.empty())
	{
		auto card = garbage.retrieveTopcard();
		boardInterface[GarbagePosition::G_row][GarbagePosition::LeftPosition] = card.getCardValue();
		boardInterface[GarbagePosition::G_row][GarbagePosition::RightPosition] = card.getCardType();
	}
}

std::vector<Player> Board::getPlayers()
{
	return players;
}