#pragma once
#include "Column.h"

class Table
{
public:
	Table();
	Table(string name, Column* column, int nbOfCols);
	Table(const Table& copy);
	Table& operator=(const Table& copy);
	~Table();

	int& operator[](int index);
	bool operator!();
	Table operator++();
	Table operator++(int);
	Table operator+();
	bool operator==(const Table& tb);
	bool operator>=(int val);

	
	friend ostream& operator<<(ostream& out, const Table& tb);
	friend istream& operator>>(istream& in, Table& tb);
private:
	string name;
	Column* column;
	int nbOfCols;
};
