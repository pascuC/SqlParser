#pragma once
#include "SQLStatement.h"

class UpdateStatement : public SqlStatement
{
public:
	UpdateStatement(string querry);
	~UpdateStatement();

private:

};