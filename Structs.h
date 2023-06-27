#pragma once
#include <string>

enum PlayerRow
{
	player1 = 1,
	player2 = 5,
};

enum CardPositions
{
	card1 = 3,
	card2 = 8,
	card3 = 13,
	card4 = 18,
	card5 = 23,
};

enum class CardTypes
{
	empty = 0,
	clubs = 1,
	diamonds = 2,
	hearts = 3,
	spades = 4,
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
	leftPosition = 10,
	rightPosition = 11,
};
