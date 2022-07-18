#pragma once
#include <cstring>

namespace my_namespace
{
    struct cstring
    {
        const char *ptr = 0;
        const char *begin() const { return ptr; } // return empty string if we are null
        const char *end() const { return ptr + strlen(ptr); }
    };
}

void rangeBasedLoopDemo()
{
    my_namespace::cstring str{"abc"};
    for (char c : str)
    {
        std::cout << c;
    }
    std::cout << "\n";
}