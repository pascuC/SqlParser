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

	friend ostream& operator<<(ostream& out, const Table& tb);
	friend istream& operator>>(istream& in, Table& tb);
};

