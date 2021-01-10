#include "DeleteCmd.h"
#include "Utils.h"
#include "Table.h"

string DeleteCmd::get_table_name()
{
	string table_name = _cmd.substr(12, _cmd.find(" ", 12) - 12);
	if (!Utils::file_exists(table_name + ".def"))
	{
		string message = "The table " + table_name + " does not exist!";
		throw message;
	}

	return table_name;
}

vector<string> DeleteCmd::get_condition()
{
	string condition_string = _cmd.substr(_cmd.find("WHERE") + 6);
	auto condition = Utils::tokenize_string(condition_string, "=", 0);
	return condition;
}

DeleteCmd::DeleteCmd(string cmd)
	: SqlStatement(cmd)
{
	// DELETE FROM table_name WHERE col=val
}

void DeleteCmd::Execute()
{
	try {
		string table_name = get_table_name();
		Table table(table_name);
		table.ReadTable();

		vector<string> condition = get_condition();
		int pos = 0;
		auto cols = table.GetColumns();
		for (int i = 0; i < cols.size(); i++) {
			if (cols[i].GetName() == condition[0])
			{
				pos = i;
				break;
			}
		}

		table.RemoveDataEntry(pos, condition[1]);
	}
	catch (string msg) {
		throw msg;
	}
}
