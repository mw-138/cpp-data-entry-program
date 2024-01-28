#include "Database.h"

void Database::HandleUserInput()
{
	switch (_currentView)
	{
	case MainMenu:
		HandleMainMenuView();
		break;
	case Table:
		HandleTableView();
		break;
	default:
		break;
	}
}

void Database::CreateTable(std::string id)
{
	ClearTerminal();
	if (DoesTableExist(id)) {
		std::cout << "This table already exists!\n";
		return;
	}
	DataTable table{ id };
	_tables.push_back(table);
	std::cout << "Table has been created!\n";
}

void Database::DeleteTable(std::string id)
{
	ClearTerminal();
	if (!DoesTableExist(id)) {
		std::cout << "This table doesn't exist!\n";
		return;
	}
	DataTable table{ id };
	auto it = std::remove(_tables.begin(), _tables.end(), table);
	_tables.erase(it, _tables.end());
	std::cout << "Table has been deleted!\n";
}

bool Database::DoesTableExist(std::string id)
{
	DataTable table{ id };
	auto it = std::find(_tables.begin(), _tables.end(), table);
	return it != _tables.end();
}

void Database::ListAllTables()
{
	ClearTerminal();
	for (int i = 0; i < _tables.size(); i++) {
		DataTable table = _tables[i];
		std::cout << std::to_string(i) << " | " << table.GetId() << std::endl;
	}
}

void Database::OpenTable(DataTable* table)
{
	ClearTerminal();
	if (table == nullptr) {
		std::cout << "Table is null\n";
		return;
	}
	_currentTable = table;
	ChangeView(Table);
	std::cout << "Opened table: " << table->GetId() << std::endl;
}

void Database::CloseCurrentTable()
{
	_currentTable = nullptr;
	delete _currentTable;
	ChangeView(MainMenu);
}

void Database::Init()
{
	CreateTable("test_1");
	CreateTable("test_2");
	ListAllTables();
}

void Database::ChangeView(DatabaseView view)
{
	ClearTerminal();
	_currentView = view;
}

void Database::HandleMainMenuView()
{
	int input = HandleActionInput({ "Open Table", "List Tables", "Create Table", "Delete Table", "Exit" });
	std::string tableId;

	switch (input) {
	case 0:
		std::cout << "Enter table index:\n";
		int tableIndex;
		std::cin >> tableIndex;
		OpenTable(&_tables[tableIndex]);
		break;
	case 1:
		ListAllTables();
		break;
	case 2:
		std::cout << "Enter table id:\n";
		std::cin >> tableId;
		CreateTable(tableId);
		break;
	case 3:
		std::cout << "Enter table id:\n";
		std::cin >> tableId;
		DeleteTable(tableId);
		break;
	case 4:
		_userInputActive = false;
		break;
	}
}

void Database::HandleTableView()
{
	_currentTable->Display();

	int input = HandleActionInput({ "Add Entry", "Remove Entry", "Back To Main Menu" });
	std::string label, value;
	
	if (input == 0) {
		std::string label, value;
		std::cout << "Enter label:\n";
		std::cin >> label;
		std::cout << "Enter value:\n";
		std::cin >> value;
		DataEntry newEntry = DataEntry(label, value);
		_currentTable->AddEntry(newEntry);
		ChangeView(Table);
	}
	else if (input == 1) {
		int index;
		std::cout << "Enter entry index:\n";
		std::cin >> index;
		_currentTable->RemoveEntry(_currentTable->GetEntries()[index]);
		ChangeView(Table);
	}
	else if (input == 2) {
		ChangeView(MainMenu);
	}
}