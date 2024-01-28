#include "DataTable.h"

void DataTable::AddEntry(DataEntry entry)
{
	ClearTerminal();
	_entries.push_back(entry);
}

void DataTable::RemoveEntry(DataEntry entry)
{
	ClearTerminal();
	auto it = std::remove(_entries.begin(), _entries.end(), entry);
	_entries.erase(it, _entries.end());
}

void DataTable::Display()
{
	ClearTerminal();
	if (_entries.size() > 0) {
		for (int i = 0; i < _entries.size(); i++) {
			DataEntry entry = _entries[i];
			std::cout << std::to_string(i) << " | Id: " << entry.id << " | Label: " << entry.label << " | Value: " << entry.value << std::endl;
		}
	}
	else {
		std::cout << "No entries found.\n";
	}
}
