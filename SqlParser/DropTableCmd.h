#pragma once

#include "SQLStatement.h"


class DropTableCmd : public SqlStatement
{
private:
	string get_table_name(const string& s);

public:
	DropTableCmd(string cmd);

	// Inherited via SqlStatement
	virtual void Execute() override;

};

