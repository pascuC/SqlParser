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