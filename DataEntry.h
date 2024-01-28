#pragma once
#include <string>
#include "Utilities.h"

struct DataEntry {
	std::string id;
	std::string label;
	std::string value;

	bool operator==(const DataEntry& other) const {
		return id == other.id;
	}

	DataEntry(std::string label, std::string value) {
		id = GenerateRandomId();
		this->label = label;
		this->value = value;
	}
};