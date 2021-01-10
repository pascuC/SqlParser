#include "CmdParser.h"

#include "DeleteCmd.h"
#include "DisplayTableCmd.h"
#include "DropTableCmd.h"
#include "CreateTableCmd.h"
#include "InsertCmd.h"
#include "SelectCmd.h"
#include "UpdateCmd.h"


SqlStatement* CmdParser::GetCommand(const string& cmd)
{
	if (cmd.find("CREATE TABLE") != string::npos)
		return new CreateTableCmd(cmd);
	if (cmd.find("DISPLAY TABLE") != string::npos)
		return new DisplayTableCmd(cmd);
	if (cmd.find("DROP TABLE") != string::npos)
		return new DropTableCmd(cmd);
	if (cmd.find("INSERT INTO") != string::npos)
		return new InsertCmd(cmd);
	if (cmd.find("SELECT") != string::npos)
		return new SelectCmd(cmd);
	if (cmd.find("UPDATE") != string::npos)
		return new UpdateCmd(cmd);
	if (cmd.find("DELETE") != string::npos)
		return new DeleteCmd(cmd);
	return nullptr;
}
