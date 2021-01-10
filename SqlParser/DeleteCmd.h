#pragma once
#include "SQLStatement.h"
#include<vector>

class DeleteCmd :
    public SqlStatement
{
private:
    string get_table_name();
    vector<string> get_condition();

public:
    DeleteCmd(string cmd);
    // Inherited via SqlStatement
    virtual void Execute() override;
};

