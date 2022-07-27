#pragma once

#include <iostream>
#include <queue>

#include "Utility.hpp"

void queueDemo()
{
    printDivider();
    // FIFO
    std::queue<int> s{std::deque{1, 2, 3, 4}};
    std::cout << "Front of the queue: " << s.front() << ", back of the queue: " << s.back() << '\n';
    s.pop();
    std::cout << "After pop, front of the queue: " << s.front() << ", back of the queue: " << s.back() << '\n';
    printDivider();
}