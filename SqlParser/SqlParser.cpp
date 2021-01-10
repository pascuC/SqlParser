#include <iostream>
#include <string>
#include <vector>

#include "CreateTableCmd.h"
#include "DisplayTableCmd.h"
#include "DropTableCmd.h"
#include "SelectCmd.h"

#include "InsertCmd.h"
#include "Table.h"

using namespace std;



int main(int argc, char** argv)
{
	string s = "CREATE TABLE salut IF NOT EXISTS ((col1, integer, 0),(col2, text, 'salut'),(col3, float, 3.4))";

	string s2 = "DISPLAY TABLE salut";

	string s3 = "DROP TABLE salut";

	string insert = "INSERT INTO salut VALUES(100, 'salut costi', 9.5)";
	string insert1 = "INSERT INTO salut VALUES(201, 'salut costi', 4.52)";
	string insert2 = "INSERT INTO salut VALUES(302, 'salut costi', 5.57)";
	string insert3 = "INSERT INTO salut VALUES(403, 'salut costi', 9.5)";
	string insert4 = "INSERT INTO salut VALUES(504, 'salut costi', 9.5)";

	string del = "DELETE FROM salut WHERE col3 = 9.5";

	string sel = "SELECT (col3, col1, col2) FROM salut WHERE col1=303";

	//CreateTableCmd cmd(s);
	SqlStatement* sql = new SelectCmd(sel);
	try {
		sql->Execute();
	}
	catch (string msg) {
		cout << msg;
	}
}