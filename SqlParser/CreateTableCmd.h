#pragma once
#include<string>
#include<vector>

#include "SQLStatement.h"
#include "Column.h"

using namespace std;

class CreateTableCmd : public SqlStatement
{
private:
	string get_table_name(const string& s);
	vector<Column> get_cols(const string& s);
	vector<Column> parse_cols(vector<string> cols);

public:
	CreateTableCmd(string cmd);

	// Inherited via SqlStatement
	virtual void Execute() override;
};

