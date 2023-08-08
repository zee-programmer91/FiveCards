#pragma once
#include <string>

enum PlayerRow
{
	Player1Row = 1,
	Player2Row = 5,
};

enum CardPositions
{
	Card1 = 3,
	Card2 = 8,
	Card3 = 13,
	Card4 = 18,
	Card5 = 23,
};

enum class AvailableCommands
{
	Exit = 1,
	GetCardFromDeck = 2,
	GetCardFromGarbage = 3,
};

enum CardNumber
{
	ONE = 1,
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
};

enum GarbagePosition
{
	G_row = 3,
	LeftPosition = 10,
	RightPosition = 11,
};

enum Winner
{
	None = 0,
	Player1Wins = 1,
	Player2Wins = 2,
};

enum Processes
{
	CheckWinner = 0,
	CheckComputerCards = 1,
};

enum ComputerResponses
{
	CommandResponse = 1,
	CardResponse = 2,
};

enum GarbageOptions
{
	RetrieveCard = 1,
	RetrieveCardInfor = 2,
};