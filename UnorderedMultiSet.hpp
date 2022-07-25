#pragma once

#include <iostream>
#include <unordered_set>

#include "Utility.hpp"

void unorderedMultiSet()
{
    // result of equal_range is contiguous
    std::unordered_multiset<int> s1{1, 6, 4, 3, 1, 3, 5, 9};
    printAll(s1.begin(), s1.end());
    for (auto it = s1.begin(); it != s1.end();)
    {
        if (auto [first, last] = s1.equal_range(*it); first != last)
        {
            std::cout << *first << ":" << std::distance(first, last) << "  ";
            it = last;
        }
        else
        {
            ++it;
        }
    }
    printDivider();
}