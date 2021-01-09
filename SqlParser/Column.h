#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Column
{
public:
	Column();
	~Column();

private:
	string name;
	string type;
};
