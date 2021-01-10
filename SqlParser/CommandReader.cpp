#include "CommandReader.h"
#include "CmdParser.h"

#include<fstream>
#include<iostream>

CommandReader::CommandReader(const string& filename)
	: _filename(filename)
{
}

void CommandReader::ExecuteCommands()
{
	ifstream file(_filename);

	string line;
	SqlStatement* cmd;

	try {
		while (getline(file, line)) {
			cmd = CmdParser::GetCommand(line);
			if (cmd == nullptr)
				throw "The command is not valid!";
			cmd->Execute();
		}
	}
	catch (...) {
		throw;
	}

}
