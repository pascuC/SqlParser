#pragma once
#include<string>
#include<vector>

#include "Column.h"

class Table
{
private:
	string _table_name;
	vector<Column> _columns;

public:
	Table(const string& table_name, const vector<Column>& columns);
	Table(const string& table_name);

	void CreateTable();
	void ReadTable();
	void DropTable();

	// Printing table definition
	friend ostream& operator<<(ostream& out, const Table& tb);

	const vector<Column> GetColumns() const { return _columns; }

	// Insert data into data file.
	void operator+(const vector<string>& values);

	// Delete data from data file.
	void RemoveDataEntry(int columnPos, const string& value);

	// Update data into data file.
	void UpdateDataEntry(int columnPos, const string& columnValue, const vector<string>& values);

	// Read data from data file.
	vector<vector<string>> ReadData();
};

