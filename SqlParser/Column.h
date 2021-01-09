#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

enum DataTypes {
	Text,
	Integer, 
	Float
};

class Column
{
public:
	Column(string name, DataTypes type, string def_val);
	Column(string name, string type, string def_val);
	~Column();

	const string& GetName() const { return _name; }
	const DataTypes& GetType() const { return _type; }
	const string& GetDefVal() const { return _def_val; }

	friend ostream& operator<<(ostream& out, const Column& col);

private:
	string _name;
	DataTypes _type;
	string _def_val;
};
