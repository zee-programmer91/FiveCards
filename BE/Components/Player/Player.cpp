#include "Player.h"

Player::Player(bool computer) : computerPlayer(computer){}

Card Player::getCard(int position)
{
	position--;
	Card card = cards[position];

	return card;
}

std::array<Card, 5> Player::getPlayerCards()
{
	return cards;
}

void Player::setCard(int position, Card newCard)
{
	position--;
	cards[position] = newCard;
}

bool Player::isComputer()
{
	return computerPlayer;
}