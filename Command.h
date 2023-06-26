#pragma once

#include <string>
#include <vector>

class Command
{
	public:
		Command(std::string instruction);
		static Command createCommand(std::string command);
		std::string getCommandName();
	private:
		std::string name;
};