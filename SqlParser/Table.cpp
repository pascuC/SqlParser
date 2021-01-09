#include "Table.h"
#include "Utils.h"

Table::Table(const string& table_name, const vector<Column>& columns)
	: _table_name(table_name), _columns(columns)
{
}

Table::Table(const string& table_name)
	: _table_name(table_name), _columns()
{
}

void Table::CreateTable()
{
	if (Utils::file_exists(_table_name + ".def"))
		return;
	ofstream table;
	table.open(_table_name + ".def");
	for (auto col : _columns)
	{
		table << col.GetName() << " ";
		switch (col.GetType())
		{
		case DataTypes::Text:
			table << "Text " << col.GetDefVal();
			break;
		case DataTypes::Integer:
			table << "Integer " << stoi(col.GetDefVal());
			break;
		case DataTypes::Float:
			table << "Float " << stof(col.GetDefVal());
			break;
		default:
			break;
		}
		table << endl;
	}
	table.close();
	table.open(_table_name + ".data");
	table.close();
}

void Table::ReadTable()
{
	ifstream table(_table_name + ".def");
	string name, type, def_val;
	while (table >> name >> type >> def_val) {
		_columns.push_back(Column(name, type, def_val));
	}
}

ostream& operator<<(ostream& out, const Table& tb)
{
	out << "Table name: " << tb._table_name << endl;
	out << "Columns: " << endl;
	for (auto &col : tb._columns)
	{
		out << col << endl;
	}
	return out;
}

istream& operator>>(istream& in, Table& tb)
{
	cout << "Table name: ";
	in >> ws;
	getline(in, tb._table_name);
	cout << endl;
	
  return in;
}

void Table::DropTable()
{
	if (remove((_table_name + ".def").c_str()))
		throw "Error dropping table" + _table_name;
	if(remove((_table_name + ".data").c_str()))
		throw "Error dropping table" + _table_name;
}
