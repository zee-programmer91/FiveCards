#include "GetCardFromGarbage.h"
#include <iostream>

bool GetCardFromGarbage::execute()
{
	std::cout << "Executed command '" << name << "'\n";
	return true;
}