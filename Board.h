#pragma once
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
		Board(std::string filePath, std::vector<Player>& players);
		~Board();
		void displayBoard();
	private:
		void readFromFile();
		void refreshBoard();
		std::vector<std::vector<std::string>> boardInterface{};
		std::ifstream interfaceFile{};
		std::vector<Player>& players;
};