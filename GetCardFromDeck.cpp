#include "GetCardFromDeck.h"
#include <iostream>

bool GetCardFromDeck::execute()
{
	std::cout << "Executed command '" << name << "'\n";
	return true;
}