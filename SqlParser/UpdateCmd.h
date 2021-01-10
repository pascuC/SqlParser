#pragma once
#include "SQLStatement.h"

#include<vector>


class UpdateCmd :
    public SqlStatement
{
    string get_table_name();
    vector<string> get_condition();
    vector<string> get_set_condition();

public:
    UpdateCmd(string cmd);

    // Inherited via SqlStatement
    virtual void Execute() override;
};

