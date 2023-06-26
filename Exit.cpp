#include "Exit.h"
#include <iostream>

bool Exit::execute()
{
	std::cout << "Executed command '" << name << "'\n";
	return false;
}