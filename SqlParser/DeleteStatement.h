#pragma once
#include "SQLStatement.h"

class DeleteStatement : public SqlStatement
{
public:
	DeleteStatement(string querry);
	~DeleteStatement();


private:
	string tableName;
	string columnName;
	string value;
};
