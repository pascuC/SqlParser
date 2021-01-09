#include <iostream>
#include <string>
#include <vector>

#include "CreateTableCmd.h"
#include "DisplayTableCmd.h"
#include "DropTableCmd.h"

#include "InsertCmd.h"

using namespace std;



int main(int argc, char** argv)
{
	string s = "CREATE TABLE salut IF NOT EXISTS ((col1, integer, 0),(col2, text, 'salut'),(col3, float, 3.4))";

	string s2 = "DISPLAY TABLE salut";

	string s3 = "DROP TABLE salut";

	string insert = "INSERT INTO salut VALUES(44, 'salut ionut', 9.5)";

	//CreateTableCmd cmd(s);
	SqlStatement* sql = new InsertCmd(insert);
	try {
		sql->Execute();
	}
	catch (string msg) {
		cout << msg;
	}
}