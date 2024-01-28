#include "Utilities.h"

int HandleActionInput(std::vector<std::string> actions)
{
	std::string message;
	size_t size = actions.size();

	if (size <= 0) {
		return -1;
	}

	for (int i = 0; i < size; i++) {
		message += "| " + std::to_string(i) + " - " + actions[i] + " ";
		if (i == size - 1) {
			message += "|";
		}
	}

	std::string line;
	for (int i = 0; i < message.length(); i++) {
		line += "-";
	}

	std::cout << line << std::endl;
	std::cout << message << std::endl;
	std::cout << line << std::endl;

	std::cout << "Enter Option (Number):\n";

	int input;
	std::cin >> input;

	if (input >= 0 || input < size) {
		return input;
	}

	return -1;
}

std::string GenerateRandomId()
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));
	std::stringstream idStream;
	idStream << "entry_" << std::time(nullptr) * std::rand();
	return idStream.str();
}

void ClearTerminal()
{
	system("cls");
}
