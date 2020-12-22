#pragma once
#include "SQLStatement.h"

class SelectStatement : public SqlStatement
{
public:
	SelectStatement(string querry);
	~SelectStatement();

private:

};
