#include "config.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stack>

void convert()
{
    std::stack<std::string> __st;
    std::string __line;

    while (std::getline(fin, __line))
    {
        compress_ws(__line);
        if (has_prefix(__line, "program"))
            continue;
        if (has_prefix(__line, "const"))
        {
            __st.push("const");
            if (__line.size() > 6)
            {
                std::string __tmp = __line.substr(6);
                context_conv(__st.top(), __tmp);
            }
            continue;
        }
        if (has_prefix(__line, "var"))
        {
            __st.push("var");
            if (__line.size() > 4)
            {
                std::string __tmp = __line.substr(4);
                context_conv(__st.top(), __tmp);
            }
            continue;
        }
        if (has_prefix(__line, "begin"))
        {
            __st.push("body");
            fout << "{\n";
            if (__line.size() > 6)
            {
                std::string __tmp = __line.substr(6);
                context_conv(__st.top(), __tmp);
            }
            continue;
        }
        if (has_prefix(__line, "end"))
        {
            std::string __tmp = __st.top();
            if (__tmp == "body") __st.pop();
            else throw std::runtime_error("fatal error: begin/end "
                "not matched");
            fout << "}\n";
            continue;
        }

        context_conv(__st.empty()?std::string("code"):__st.top(), __line);
    }
}

void context_conv(const std::string& __type, std::string& __context)
{
    token_conv(__context);
    std::cerr<<"D> type: "<<__type<<std::endl;
    if (__type == "const")
        const_conv(__context);
    else if (__type == "var")
        var_conv(__context);
    else if (__type == "body")
        code_conv(__context);
    else if (__type == "code")
        code_conv(__context);
    else
        throw std::runtime_error(std::string("error: unknown keyword: ")
            + __type);
}

void token_conv(std::string& __src)
{
    std::size_t __loc = 0;

    while ((__loc = __src.find("{", __loc)) != std::string::npos)
        __src.replace(__loc, 1, std::string("/*"));

    __loc = 0;

    while ((__loc = __src.find("}", __loc)) != std::string::npos)
        __src.replace(__loc, 1, std::string("*/"));
}

void code_conv(std::string& __src)
{
    fout << __src << '\n';
}
