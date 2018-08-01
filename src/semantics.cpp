#include "config.h"
#include <string>
#include <iostream>
#include <cctype>

void compress_ws(std::string& __s)
{
    while (isspace(__s.front())) __s.erase(__s.begin());
    while (isspace(__s.back())) __s.pop_back();
    // TODO: compress whitespace between words to only one
}

bool has_prefix(const std::string& __s, const std::string& __pre)
{
    if (__pre.size() > __s.size()) return false;
    for (size_t __i = 0; __i < __pre.size(); ++__i)
        if (__s[__i] != __pre[__i]) return false;
    return true;
}

std::string next_statement(std::string& __src)
{
    std::size_t __pos = __src.find(';');
    if (__pos == std::string::npos)
        return {};
    std::string __ret = __src.substr(0, __pos); // excluding ';'
    __src.erase(0, __pos + 1);
    std::cerr<<"D> ret="<<__ret<<" | src="<<__src<<std::endl;
    return __ret;
}
