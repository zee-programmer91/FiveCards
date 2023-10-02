#include "../Card.h"
#include "../Deck.h"
#include "../Player.h"
#include "../Command.h"
#include "../Garbage.h"

#include "pch.h"

TEST(CardTest, TestingCardConstructor) {
  FC::Card card( "1", FC::CardTypes::H);

  EXPECT_EQ(card.getCardValue(), "1");
  EXPECT_EQ(card.getCardType(), FC::CardTypes::H);
}
