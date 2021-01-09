#include"Table.h"
Table::Table()
{
	this->name = "";
	this->nbOfCols = 0;
	this->column = nullptr;
}

Table::Table(string name, Column* column, int nbOfCols)
{
	this->name = name;
	if (column != nullptr && nbOfCols > 0)
	{
		this->nbOfCols = nbOfCols;
		this->column = new Column[nbOfCols];
		for (int i = 0; i < nbOfCols; i++)
		{
			this->column[i] = column[i];
		}
	}
	else
	{
		this->column = nullptr;
		this->nbOfCols = 0;
	}
}

Table::Table(const Table& copy)
{
	this->name = copy.name;
	if (copy.column != nullptr && copy.nbOfCols > 0)
	{
		this->nbOfCols = copy.nbOfCols;
		this->column = new Column[copy.nbOfCols];
		for (int i = 0; i < copy.nbOfCols; i++)
		{
			this->column[i] = copy.column[i];
		}
	}
	else
	{
		this->column = nullptr;
		this->nbOfCols = 0;
	}
}

Table& Table::operator=(const Table& copy)
{
	if (this->column != nullptr)
	{
		delete[] this->column;
	}

	this->name = copy.name;
	if (copy.column != nullptr && copy.nbOfCols > 0)
	{
		this->nbOfCols = copy.nbOfCols;
		this->column = new Column[copy.nbOfCols];
		for (int i = 0; i < copy.nbOfCols; i++)
		{
			this->column[i] = copy.column[i];
		}
	}
	else
	{
		this->column = nullptr;
		this->nbOfCols = 0;
	}
}

//ostream& operator<<(ostream& out, const Table& tb)
//{
//	out << "Table name: " << tb.name << endl;
//	out << "Number of cols: " << tb.nbOfCols << endl;
//	for (int i = 0; i < tb.nbOfCols; i++)
//	{
//		out << "Col[" << i << "]: " << tb.column[i] << endl;
//	}
//	return out;
//}

//istream& operator>>(istream& in, Table& tb)
//{
//	cout << "Table name: ";
//	in >> ws;
//	getline(in, tb.name);
//	cout << "Number of cols: ";
//	in >> tb.nbOfCols;
//	cout << endl;
//	if (in.good() && tb.nbOfCols > 0)
//	{
//		tb.column = new Column[tb.nbOfCols];
//		for (int i = 0; i < tb.nbOfCols; i++)
//		{
//			in >> tb.column[i];
//		}
//	}
//  return in;
//}

Table::~Table()
{
	if (this->column != nullptr)
	{
		delete[] this->column;
	}
}