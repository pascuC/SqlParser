#pragma once
#include "SQLStatement.h"
#include<vector>

class SelectCmd :
    public SqlStatement
{
private:
    string get_table_name(const string& s);
    bool are_all_req();
    vector<string> get_selected_cols();
    bool is_conditioned();
    vector<string> get_condition();

public:
    SelectCmd(string cmd);

    // Inherited via SqlStatement
    virtual void Execute() override;
};

