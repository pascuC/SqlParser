#include "Table.h"
#include "Utils.h"

void Table::empty_file()
{
	ofstream myfile(_table_name + ".data", ios::trunc);
	myfile.close();
}

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

void Table::DropTable()
{
	if (remove((_table_name + ".def").c_str()))
		throw "Error dropping table" + _table_name;
	if(remove((_table_name + ".data").c_str()))
		throw "Error dropping table" + _table_name;
}

void Table::operator+(const vector<string>& values)
{
	ofstream data(_table_name + ".data", ios::app | ios::binary);
	int len = 0, valuei = 0;
	float valuef = 0;
	for (int i = 0; i < _columns.size(); i++) {
		switch (_columns[i].GetType())
		{
		case DataTypes::Text:
			len = values[i].length();
			data.write((char*)&len, sizeof(int));
			data.write(values[i].c_str(), len);
			break;
		case DataTypes::Integer:
			valuei = stoi(values[i]);
			data.write((char*)&valuei, sizeof(int));
			break;
		case DataTypes::Float:
			valuef = stof(values[i]);
			data.write((char*)&valuef, sizeof(float));
			break;
		default:
			break;
		}
	}
	data.close();
}

void Table::RemoveDataEntry(int columnPos, const string& value)
{
	auto data = ReadData();
	empty_file();
	bool is_row_printed;
	for (auto line : data) {
		is_row_printed = true;
		switch (_columns[columnPos].GetType())
		{
		case DataTypes::Text:
			if (line[columnPos] == value)
				is_row_printed = false;
			break;
		case DataTypes::Integer:
			if (stoi(line[columnPos]) == stoi(value))
				is_row_printed = false;
			break;
		case DataTypes::Float:
			if (stof(line[columnPos]) == stof(value))
				is_row_printed = false;
			break;
		default:
			break;
		}
		if (is_row_printed)
			this->operator+(line);
	}
}

void Table::UpdateDataEntry(int columnPos, const string& columnValue, int updatedPos, const string& updatedValue)
{
	auto data = ReadData();
	empty_file();
	for (auto line : data) {
		if (line[columnPos] == columnValue)
			line[updatedPos] = updatedValue;
		this->operator+(line);
	}
}

vector<vector<string>> Table::ReadData()
{
	string line;
	ifstream myfile(_table_name + ".data", ios::binary);

	if (!myfile.is_open())
	{
		throw "Error opening the file!";
	}

	vector<vector<string>> lines;
	int len = 0, valuei = 0;
	float valuef = 0;
	char* value = nullptr;

	while (!myfile.eof())
	{
		vector<string> line;
		for (int i = 0; i < _columns.size(); i++) {
			switch (_columns[i].GetType())
			{
			case DataTypes::Text:
				myfile.read((char*)&len, sizeof(int));
				value = new char[len + 1];
				myfile.read(value, len);
				value[len] = '\0';
				line.push_back(value);
				break;
			case DataTypes::Integer:
				myfile.read((char*)&valuei, sizeof(int));
				line.push_back(to_string(valuei));
				break;
			case DataTypes::Float:
				myfile.read((char*)&valuef, sizeof(float));
				line.push_back(to_string(valuef));
				break;
			default:
				break;
			}
		}
		lines.push_back(line);
	}

	delete value;

	lines.pop_back();

	return lines;
}

