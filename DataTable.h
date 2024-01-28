#pragma once
#include <string>
#include <vector>
#include "DataEntry.h"

class DataTable {
private:
	std::string _id;
	std::vector<DataEntry> _entries;
public:
	std::string GetId() const { return _id; }
	std::vector<DataEntry> GetEntries() const { return _entries; }

	void AddEntry(DataEntry entry);
	void RemoveEntry(DataEntry entry);
	void Display();

	bool operator==(const DataTable& other) const {
		return _id == other.GetId();
	}

	DataTable(std::string id) {
		_id = id;
		_entries = std::vector<DataEntry>();
	}
};