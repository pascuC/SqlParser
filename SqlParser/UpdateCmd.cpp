#include "UpdateCmd.h"
#include "Utils.h"
#include "Table.h"

string UpdateCmd::get_table_name()
{
	string table_name = _cmd.substr(7, _cmd.find(" ", 7) - 7);
	if (!Utils::file_exists(table_name + ".def"))
	{
		string message = "The table " + table_name + " does not exist!";
		throw message;
	}

	return table_name;
}

vector<string> UpdateCmd::get_condition()
{
	string condition_string = _cmd.substr(_cmd.find("WHERE") + 6);
	vector<string> condition = Utils::tokenize_string(condition_string, "=", 0);
	return condition;
}

vector<string> UpdateCmd::get_set_condition()
{
	string condition_string = _cmd.substr(_cmd.find("SET") + 4, _cmd.find("WHERE") - _cmd.find("SET") - 5);
	vector<string> condition = Utils::tokenize_string(condition_string, "=", 0);
	return condition;
}

UpdateCmd::UpdateCmd(string cmd)
	: SqlStatement(cmd)
{
	// UPDATE table_name
	// SET col=val WHERE col=val
}

void UpdateCmd::Execute()
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

		vector<string> updated = get_set_condition();
		int updatePos = 0;
		for (int i = 0; i < cols.size(); i++) {
			if (cols[i].GetName() == updated[0])
			{
				updatePos = i;
				break;
			}
		}

		table.UpdateDataEntry(pos, condition[1], updatePos, updated[1]);
	}
	catch (string msg) {
		throw msg;
	}
}
