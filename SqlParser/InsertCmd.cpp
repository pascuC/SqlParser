#include "InsertCmd.h"
#include "Utils.h"
#include "Table.h"


string InsertCmd::get_table_name(const string& s)
{
	string table_name = s.substr(12, s.find(" ", 12) - 12);
	if (!Utils::file_exists(table_name + ".def"))
	{
		string message = "The table " + table_name + " does not exist!";
		throw message;
	}

	return table_name;
}

vector<string> InsertCmd::get_values()
{
	string values = Utils::get_str_between_two_str(_cmd, "(", ")");
	vector<string> result = Utils::tokenize_string(values, ", ", 0);
	return result;
}

bool InsertCmd::values_are_ok(const vector<string>& values, const vector<Column>& columns)
{
	if (values.size() != columns.size())
		return false;
	try
	{
		for (int i = 0; i < columns.size(); i++) {
			switch (columns[i].GetType())
			{
			case DataTypes::Integer:
				stoi(values[i]);
				break;
			case DataTypes::Float:
				stof(values[i]);
			default:
				break;
			}
		}
	}
	catch (...) {
		return false;
	}
	return true;
}

InsertCmd::InsertCmd(string cmd)
	: SqlStatement(cmd)
{
	// INSERT INTO table_name
	// VALUES (val1, val2, val3)
}

void InsertCmd::Execute()
{
	try {
		string table_name = get_table_name(_cmd);
		Table table(table_name);
		table.ReadTable();

		vector<string> values = get_values();
		if (values_are_ok(values, table.GetColumns()))
			table + values;
	}
	catch (string msg) {
		throw msg;
	}
}
