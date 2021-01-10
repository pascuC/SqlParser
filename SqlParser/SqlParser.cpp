#include "CommandReader.h"

#include<iostream>

using namespace std;



int main(int argc, char** argv)
{
	try {
		for (int i = 1; i < argc; i++) {
			CommandReader cmd(argv[i]);
			cmd.ExecuteCommands();
		}
		cout << "Commands executed succesfully!";
	}
	catch (string msg) {
		cout << msg;
	}
}