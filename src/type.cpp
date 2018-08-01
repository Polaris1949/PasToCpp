#include "config.h"
#include <string>
#include <stdexcept>

void type_conv(std::string& __t)
{
    if (__t == "byte")
        __t = "unsigned char";
    else if (__t == "shortint")
        __t = "signed char";
    else if (__t == "integer")
        __t = "short";
    else if (__t == "word")
        __t = "unsigned short";
    else if (__t == "longint")
        __t = "int";
    else if (__t == "real")
        __t = "double";
    else if (__t == "single")
        __t = "float";
    else if (__t == "double")
        __t = "double";
    else if (__t == "extended")
        __t = "long double";
    else if (__t == "comp")
        __t = "long double";
    else if (__t == "char")
        __t = "char";
    else if (__t == "boolean")
        __t = "bool";
    else
        throw std::runtime_error(std::string("Bad pascal type: ") + __t);
}

void literal_conv(std::string& __l)
{
    if (__l == "maxint")
        __l = "32767";
    else if (__l == "maxlongint")
        __l = "2147483647";
    else if (__l == "true")
        __l = "true";
    else if (__l == "false")
        __l = "false";
    else
        throw std::runtime_error(std::string("Bad pascal literal: ") + __l);
}
