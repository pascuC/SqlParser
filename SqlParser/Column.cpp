#include"Column.h"

Column::Column(string name, DataTypes type, string def_val)
{
	_name = name;
	_type = type;
	_def_val = def_val;
}

Column::Column(string name, string type, string def_val)
{
	_name = name;
	_def_val = def_val;
	if (type == "Text")
		_type = DataTypes::Text;
	else if (type == "Integer")
		_type = DataTypes::Integer;
	else
		_type = DataTypes::Float;
}

Column::~Column()
{
	
}

ostream& operator<<(ostream& out, const Column& col)
{
	string type;
	out << "Column name: " << col._name << endl;
	switch (col._type)
	{
	case DataTypes::Text :
		type = "Text";
		break;
	case DataTypes::Float:
		type = "Float";
		break;
	case DataTypes::Integer:
		type = "Integer";
		break;
	default:
		type = "";
	}
	out << "Data type: " << type << endl;
	out << "Default value: " << col._def_val << endl;
	return out;
}
