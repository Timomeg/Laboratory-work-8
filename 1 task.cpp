#include "lab.h"

char* CopyString(const char* str) {
    char* str_copy = new char[sizeof str];
    std::memcpy(str_copy, str, sizeof str);
    return str_copy;
}


char* ConcatinateStrings(const char *a, const char *b) {
    auto str_copy = new char [2];
    std::string str = a;
    str += b;
    std::copy(str.begin(),str.end()+1, str_copy);
    return str_copy;
}