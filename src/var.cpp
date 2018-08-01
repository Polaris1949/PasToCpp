#include "config.h"
#include <string>
#include <fstream>
#include <iostream>

void const_conv(std::string& __src)
{
    std::string __s;
    while (__s = next_statement(__src), !__s.empty())
    {
        __s = std::string("const auto ") + __s; // TODO: type recognization
        fout << __s << ";\n";
    }
}

void var_conv(std::string& __src)
{
    std::string __s;
    while (__s = next_statement(__src), !__s.empty())
    {
        std::size_t __pos = __s.find(':');
        std::string __type = __s.substr(__pos + 1);
        type_conv(__type);
        fout << __type << ' ';
        std::string __var = __s.substr(0, __pos);
        fout << __var << ";\n";
    }
}
