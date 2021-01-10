#pragma once

#include "SQLStatement.h"

class CmdParser
{
public:
	CmdParser();

	static SqlStatement* GetCommand(const string& cmd);
};

