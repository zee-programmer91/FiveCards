#include "Helper.h"

std::vector<std::string> Helper::Split(std::string phrase, char delimiter)
{
	std::vector<std::string> phrases{};
	std::string word = "";

	for (auto character : phrase)
	{
		if (character == delimiter)
		{
			phrases.push_back(word);
			word = "";
		}

		word += character;
	}

	if (!word.empty())
		phrases.push_back(word);

	return phrases;
}