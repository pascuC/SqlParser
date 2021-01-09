#pragma once
#include "SQLStatement.h"
#include "Column.h"

#include <vector>
#include <string>

using namespace std;

class InsertCmd :
    public SqlStatement
{
private:
    string get_table_name(const string& s);
    vector<string> get_values();

    bool values_are_ok(const vector<string>& values, const vector<Column>& columns);

public:
    InsertCmd(string cmd);

    // Inherited via SqlStatement
    virtual void Execute() override;
};

