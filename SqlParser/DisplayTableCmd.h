#pragma once

#include "SQLStatement.h"


class DisplayTableCmd : public SqlStatement
{
private:
	string get_table_name(const string& s);

public:
	DisplayTableCmd(string cmd);

	// Inherited via SqlStatement
	virtual void Execute() override;

};

