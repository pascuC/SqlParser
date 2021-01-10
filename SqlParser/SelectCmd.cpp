#include "SelectCmd.h"
#include "Table.h"
#include "Utils.h"

#include<iomanip>


string SelectCmd::get_table_name(const string& s)
{
	string table_name = s.substr(s.find("FROM") + 5, s.find(" ", s.find("FROM") + 5) - s.find(" ", s.find("FROM")));
	if (table_name.find(" ") > 0)
		table_name.pop_back();

	if (!Utils::file_exists(table_name + ".def"))
	{
		string message = "The table " + table_name + " does not exist!";
		throw message;
	}

	return table_name;
}

bool SelectCmd::are_all_req()
{
	auto all_req = _cmd.find("ALL");
	if (all_req == -1)
		return false;
	return true;
}

vector<string> SelectCmd::get_selected_cols()
{
	string cols_string = Utils::get_str_between_two_str(_cmd, "(", ")");
	vector<string> cols = Utils::tokenize_string(cols_string, ", ", 0);
	return cols;
}

bool SelectCmd::is_conditioned()
{
	auto is_cond = _cmd.find("WHERE");
	if (is_cond == -1)
		return false;
	return true;
}

vector<string> SelectCmd::get_condition()
{
	string condition_string = _cmd.substr(_cmd.find("WHERE") + 6);
	vector<string> condition = Utils::tokenize_string(condition_string, "=", 0);
	return condition;
}

SelectCmd::SelectCmd(string cmd)
	:SqlStatement(cmd)
{
	// SELECT (col1, col2) FROM table_name
	// WHERE col = value
}

void SelectCmd::Execute()
{
	try {
		string table_name = get_table_name(_cmd);
		Table table(table_name);
		table.ReadTable();

		auto data = table.ReadData();
		auto table_cols = table.GetColumns();
		vector<string> cols;
		vector<int> indexes;
		vector<string> condition;
		int index_condition;
		DataTypes type_condition;

		if(!are_all_req())
			cols = get_selected_cols();
		else
		{
			for (auto col : table_cols)
				cols.push_back(col.GetName());
		}

		for (int i = 0; i < cols.size(); i++) {
			for (int j = 0; j < table_cols.size(); j++) {
				if (cols[i] == table_cols[j].GetName()) {
					indexes.push_back(j);
					break;
				}
			}
		}

		for (auto col : cols) {
			cout << setw(20) << col << " ";
		}
		cout << endl;


		bool is_condition = is_conditioned();
		if (is_condition) {
			condition = get_condition();
			for (int i = 0; i < table_cols.size(); i++)
				if (table_cols[i].GetName() == condition[0])
				{
					index_condition = i;
					type_condition = table_cols[i].GetType();
					break;
				}
		}

		bool is_row_printed;
		for (auto line : data) {
			is_row_printed = false;
			for (auto index : indexes) {
				if (is_condition)
				{
					switch (type_condition)
					{
					case DataTypes::Text:
						if (line[index_condition].find(condition[1]) > 0)
							is_row_printed = true;
						break;
					case DataTypes::Integer:
						if (stoi(line[index_condition]) ==  stoi(condition[1]))
							is_row_printed = true;
						break;
					case DataTypes::Float:
						if (stof(line[index_condition]) == stof(condition[1]))
							is_row_printed = true;
						break;
					default:
						break;
					}
					if(is_row_printed)
						cout << setw(20) << line[index] << " ";
				}
			}
			if (is_row_printed)
				cout << endl;
		}
	}
	catch (string msg) {
		throw msg;
	}
}
