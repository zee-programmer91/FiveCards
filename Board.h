#pragma once
#include "Deck.h"
#include "Player.h"
#include "Structs.h"

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Board
{
	public:
		Board(std::string filePath, std::vector<Player>& players, Deck& deck, Garbage garbage);
		~Board();

		Winner checkWinner();
		void changePlayerTurn();
		std::map<std::string, int> countPlayerCards(Processes process);
		void displayBoard();
		void displayTitle();
		void disposeDiscardedCard(Card card);
		Card getCardFromDeck();
		Card getCardFromGarbage(GarbageOptions option);
		Player& getPlayer();
		int getPlayerTurn();
		std::vector<Player> getPlayers();
		std::string getComputerResponse(ComputerResponses response, Card newCard = Card{ "E", CardTypes::Empty });
		bool isGarbageEmpty();
		void processRequest(Player& player, const Card newCard, std::string& response);
		bool runGame();
	private:
		void readFromFile();
		void refreshBoard();
		void initializePlayerCards();
		std::vector<std::vector<std::string>> boardInterface{};
		std::ifstream interfaceFile{};
		std::vector<Player>& players;
		Deck deck;
		Garbage garbage;
		int playerTurn = 2;
};