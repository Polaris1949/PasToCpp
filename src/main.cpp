// Pascal to C++
#include "config.h"
#include <iostream>
#include <fstream>
#include <string>

void help()
{
    std::cerr << "Usage: p2c [OPTION]... FILENAME[...]" << std::endl;
}

void version()
{
    std::cerr << "p2c (Polaris language utils) 1.0" << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc < 2) return 0;

    if (argc == 2)
    {
        if (std::string(argv[1]) == "--help")
        {
            help();
            return 0;
        }

        if (std::string(argv[1]) == "--version")
        {
            version();
            return 0;
        }

        std::string __name = argv[1];
        open_file(__name);
        convert();
        close_file();
        return 0;
    }

    std::cerr << "Bad usage! Please use option --help for more information."
        << std::endl;
    return 1;
}
