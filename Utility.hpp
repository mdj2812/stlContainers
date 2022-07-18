#pragma once

#include <iostream>

void printDivider()
{
    std::cout << "\n*******************************************\n";
}

template <typename InputIt>
void printAll(const InputIt begin, const InputIt end)
{
    if (begin == end)
    {
        std::cout << "{}\n";
        return;
    }
    std::cout << "{";
    for (auto it = begin; it != end; ++it)
    {
        std::cout << *it << ",";
    }
    std::cout << "\b}\n";
}

void dumpMem(const void *mem, unsigned int n)
{
    const char *p = reinterpret_cast<const char *>(mem);
    for (unsigned int i = 0; i < n; i++)
    {
        std::cout << std::hex << int(p[i]) << " ";
    }
    std::cout << std::endl;
}
