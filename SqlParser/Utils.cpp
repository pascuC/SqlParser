#include "Utils.h"

string Utils::get_str_between_two_str(const string& s, const string& start_delim, const string& stop_delim)
{
    unsigned first_delim_pos = s.find(start_delim);
    unsigned end_pos_of_first_delim = first_delim_pos + start_delim.length();
    unsigned last_delim_pos = s.find_last_of(stop_delim);

    return s.substr(end_pos_of_first_delim,
        last_delim_pos - end_pos_of_first_delim);
}

vector<string> Utils::tokenize_string(const string& s, const string& delim, size_t start)
{
    vector<string> result;
    auto end = s.find(delim);
    while (end != std::string::npos)
    {
        result.push_back(s.substr(start, end - start));
        start = end + delim.length();
        end = s.find(delim, start);
    }
    result.push_back(s.substr(start, end));
    return result;
}

bool Utils::file_exists(const std::string& name)
{
    if (FILE* file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    }
    else {
        return false;
    }
}