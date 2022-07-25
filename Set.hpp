#pragma once

#include <algorithm>
#include <iostream>
#include <set>

#include "Point.hpp"
#include "Utility.hpp"

void setDemo()
{
    // set of objects
    std::set<Point> points = {{3, 4}, {4, 3}, {1, 2}, {3, 4}, {1, 3}};
    printAll(points.begin(), points.end());
    std::cout << "Try to emplace a duplicated point, sets after insertion:\n";
    auto res = points.insert(Point{1.0f, 2.0f});
    printAll(points.begin(), points.end());
    std::cout << "The returned iterator value: {" << *(res.first) << ", " << res.second << "}\n";
    printDivider();

    // erase items in loop
    const std::set<int> c = {1, 2, 3, 4, 1, 2, 3, 4};
    printAll(c.begin(), c.end());
    std::cout << "Erase all odd numbers:\n";
    auto tmp = c;
    for (auto it = tmp.begin(); it != tmp.end();)
    {
        if (*it % 2 != 0)
            it = tmp.erase(it);
        else
            ++it;
    }
    printAll(tmp.begin(), tmp.end());
    // or alternatively, use std::erase_if
    tmp = c;
    std::erase_if(tmp, [](int v)
                  { return v % 2; });
    printAll(tmp.begin(), tmp.end());
    printDivider();

    // equal_range
    auto range = c.equal_range(2);
    std::cout << "Result of equal range: ";
    printAll(range.first, range.second);
    printDivider();
}