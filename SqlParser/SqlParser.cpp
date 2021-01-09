#include <iostream>
#include <string>
#include <vector>

#include "CreateTableCmd.h"
#include "DisplayTableCmd.h"
#include "DropTableCmd.h"

using namespace std;



int main(int argc, char** argv)
{
	string s = "CREATE TABLE salut IF NOT EXISTS ((col1, integer, 0),(col2, text, 'salut'),(col3, float, 3.4))";

	string s2 = "DISPLAY TABLE salut";

	string s3 = "DROP TABLE salut";

	//CreateTableCmd cmd(s);
	SqlStatement* sql = new DropTableCmd(s3);

	try {
		sql->Execute();
	}
	catch (string msg) {
		cout << msg;
	}
}