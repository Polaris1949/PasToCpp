#include "config.h"
#include <string>
#include <fstream>
#include <iostream>

std::ifstream fin;
std::ofstream fout;

void open_file(const std::string& __name)
{
    fin.open(__name + ".pas");
    fout.open(__name + ".cpp");
}

void close_file()
{
    fin.close();
    fout.close();
}
