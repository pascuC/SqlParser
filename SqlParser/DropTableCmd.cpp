#include "DropTableCmd.h"
#include "Utils.h"

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
		if (remove((table_name + ".def").c_str()) != 0)
			throw "Error droping table";
		}
	catch (string msg) {
		throw msg;
	}
}
