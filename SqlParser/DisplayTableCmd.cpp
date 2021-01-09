#include "DisplayTableCmd.h"
#include "Utils.h"
#include "Table.h"

string DisplayTableCmd::get_table_name(const string& s)
{
	string table_name = s.substr(14, s.find(" ", 14) - 14);
	if (!Utils::file_exists(table_name + ".def"))
	{
		string message = "The table " + table_name + " does not exist!";
		throw message;
	}
	return table_name;
}

DisplayTableCmd::DisplayTableCmd(string cmd)
	:SqlStatement(cmd)
{
	// DISPLAY TABLE table_name
}

void DisplayTableCmd::Execute()
{
	try {
		string table_name = get_table_name(_cmd);
		Table table(table_name);
		table.ReadTable();
		cout << table;
	}
	catch (string msg) {
		throw msg;
	}
}
