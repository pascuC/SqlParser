#include "CreateTableCmd.h"
#include "Utils.h"
#include "Table.h"

string CreateTableCmd::get_table_name(const string& s)
{
	string table_name = s.substr(13, s.find(" ", 13) - 13);
	int if_not_exists = s.find("IF NOT EXISTS");
	if (Utils::file_exists(table_name + ".def") && if_not_exists == -1)
	{
		string message = "The table " + table_name + " already exists!";
		throw message;
	}

	return table_name;
}

vector<Column> CreateTableCmd::get_cols(const string& s)
{
	string cols = Utils::get_str_between_two_str(s, "(", ")");
	vector<string> result = Utils::tokenize_string(cols, "),(", 1);
	if (result.size() < 1)
		throw "There must be at least one column for the table definition!";
	result[result.size() - 1] = result[result.size() - 1].erase(result[result.size() - 1].find(")"));
	return parse_cols(result);
}

vector<Column> CreateTableCmd::parse_cols(vector<string> cols)
{
	vector<Column> result;
	int col_number = 0;
	for (auto col : cols)
	{
		vector<string> col_def = Utils::tokenize_string(col, ", ", 0);
		if (col_def.size() != 3)
		{
			string message = "The column definition is not correct! Column number: " + col_number;
			throw message;
		}
		DataTypes type;
		if (col_def[1] == "text")
			type = DataTypes::Text;
		else if (col_def[1] == "integer")
			type = DataTypes::Integer;
		else if (col_def[1] == "float")
			type = DataTypes::Float;
		else
		{
			string message = "Data type not allowed! Column number: " + col_number;
			throw message;
		}

		result.push_back(Column(col_def[0], type, col_def[2]));
		col_number++;
	}
	return result;
}

CreateTableCmd::CreateTableCmd(string cmd)
	: SqlStatement(cmd)
{
	// CREATE TABLE table_name [IF NOT EXISTS] 
	// (
	//	(col_name, type, def_val)
	// )
}

void CreateTableCmd::Execute()
{
	try {
		string table_name = get_table_name(_cmd);
		vector<Column> cols = get_cols(_cmd);

		Table table(table_name, cols);
		table.CreateTable();
	}
	catch (string msg)
	{
		throw msg;
	}
}
