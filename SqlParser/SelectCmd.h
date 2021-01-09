#pragma once
#include "SQLStatement.h"

class SelectCmd :
    public SqlStatement
{

public:
    SelectCmd(string cmd);

    // Inherited via SqlStatement
    virtual void Execute() override;
};

