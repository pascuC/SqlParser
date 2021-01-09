#pragma once
#include<string>
#include<vector>
#include<fstream>

using namespace std;

class Utils
{
public:
    static string get_str_between_two_str(const string& s,
        const string& start_delim,
        const string& stop_delim);

    static vector<string> tokenize_string(const string& s,
        const string& delim,
        size_t start);

    static bool file_exists(const string& name);
};

