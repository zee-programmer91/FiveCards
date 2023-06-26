#include "Player.h"
#include "Print.cpp"

Card Player::getCard(int position)
{
	position--;
	Card card = cards[position];

	return card;
}

void Player::setCard(int position, Card newCard)
{
	position--;
	cards[position] = newCard;
}