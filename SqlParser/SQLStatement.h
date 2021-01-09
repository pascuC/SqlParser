#pragma once
#include <string>

using namespace std;

class SqlStatement
{
protected:
	string _cmd;

public:
	SqlStatement(string cmd);

	virtual void Execute() = 0;
};
