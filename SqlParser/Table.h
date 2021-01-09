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
};

