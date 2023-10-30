#include <iostream>
#include <string>

static void printErrMessage(std::string classname, std::string errorMessage)
{
	std::cout << classname << "ERROR: " << errorMessage << "\n";
}