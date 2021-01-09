#include "DropTableCmd.h"
#include "Utils.h"
#include "Table.h"

string DropTableCmd::get_table_name(const string& s)
{
	string table_name = s.substr(11, s.find(" ", 11) - 11);
	if (!Utils::file_exists(table_name + ".def"))
	{
		string message = "The table " + table_name + " does not exist!";
		throw message;
	}
	return table_name;
}

DropTableCmd::DropTableCmd(string cmd)
	: SqlStatement(cmd)
{
	// DROP TABLE table_name
}

void DropTableCmd::Execute()
{
	try {
		string table_name = get_table_name(_cmd);
		Table table(table_name);
		table.DropTable();
	}
	catch (string msg) {
		throw msg;
	}
}
