#ifndef _P2C_CONFIG_H
#define _P2C_CONFIG_H 1

#include <string>
#include <fstream>

extern std::ifstream fin;
extern std::ofstream fout;

// main
void help();
void version();

// type
void type_conv(std::string& __t);
void literal_conv(std::string& __l);

// convert
void convert();
void context_conv(const std::string& __type, std::string& __context);
void token_conv(std::string& __src);
void code_conv(std::string& __src);

// var
void const_conv(std::string& __src);
void var_conv(std::string& __src);

// fileio
void open_file(const std::string& __name);
void close_file();

// semantics
void compress_ws(std::string& __s);
bool has_prefix(const std::string& __s, const std::string& __pre);
std::string next_statement(std::string& __src);

#endif
