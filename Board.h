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
		void displayBoard();
		void displayTitle();
		void disposeDiscardedCard(Card card);
		Card getCardFromDeck();
		Card getCardFromGarbage();
		int getPlayerTurn();
		Player& getPlayer();
		bool isGarbageEmpty();
		void processRequest(Player& player, const CardNumber cardNumber, const Card newCard);
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