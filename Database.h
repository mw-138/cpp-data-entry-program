#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "DataTable.h"
#include "Utilities.h"

enum DatabaseView {
	MainMenu,
	Table
};

class Database {
private:
	std::vector<DataTable> _tables;
	bool _userInputActive;
	DatabaseView _currentView;
	DataTable* _currentTable;
public:
	void HandleUserInput();
	void CreateTable(std::string id);
	void DeleteTable(std::string id);
	bool DoesTableExist(std::string id);
	void ListAllTables();
	void OpenTable(DataTable* table);
	void CloseCurrentTable();
	void Init();
	void ChangeView(DatabaseView view);
	void HandleMainMenuView();
	void HandleTableView();

	bool GetUserInputActive() const { return _userInputActive; }

	Database() {
		_userInputActive = true;
		_currentTable = nullptr;
		_currentView = MainMenu;
		_tables = std::vector<DataTable>();
		Init();
	}

	~Database() {
		delete _currentTable;
	}
};