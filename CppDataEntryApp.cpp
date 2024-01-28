#include <iostream>
#include "Database.h"

int main()
{
	Database db{};
	while (db.GetUserInputActive()) {
		db.HandleUserInput();
	}
}