#pragma once

#include <iostream>
#include <queue>

#include "Point.hpp"
#include "Utility.hpp"

template <typename T>
// NB: pass by value so the print uses a copy
void print_queue(T q)
{
    while (!q.empty())
    {
        std::cout << q.top() << ' ';
        q.pop();
    }
    std::cout << '\n';
}

void priorityQueueDemo()
{
    // initialization by push one-by-one
    std::priority_queue<int> q;
    const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
    for (int n : data)
    {
        q.push(n);
    }
    print_queue(q);
    printDivider();

    // initialization by range
    std::vector<Point> points = {{3, 4}, {4, 3}, {1, 2}, {3, 4}, {1, 3}};
    std::priority_queue<Point, std::vector<Point>, std::greater<Point>> q2(points.begin(), points.end());
    // equivalent to
    // std::priority_queue<Point> q2(std::greater<Point>(), points);
    print_queue(q2);
    printDivider();
}