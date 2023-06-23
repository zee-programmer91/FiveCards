#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Board
{
	public:
		Board(std::string filePath);
		~Board();
		void displayBoard();
	private:
		void readFromFile();
		std::vector<std::string> boardInterface{};
		std::ifstream file{};
};