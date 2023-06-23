#include "Board.h"

Board::Board(std::string filePath)
{
	file.open(filePath);
	readFromFile();
}

Board::~Board()
{
	file.close();
}

void Board::displayBoard()
{
	for (const auto row : boardInterface)
	{
		std::cout << row << "\n";
	}
}

void Board::readFromFile()
{
	std::string row{};
	while (!file.eof())
	{
		std::getline(file, row);
		boardInterface.push_back(row);
	}
}