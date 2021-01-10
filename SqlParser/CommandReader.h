#pragma once
#include<string>

using namespace std;

class CommandReader
{
private:
	string _filename;

public:
	CommandReader(const string& filename);

	void ExecuteCommands();
};

