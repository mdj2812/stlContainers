#pragma once
#include <array>
#include <deque>
#include <iostream>
#include <vector>

#include "Utility.hpp"

void dequeDemo()
{
    // the elements of a deque are not stored contiguously
    std::deque<int> d(8);
    d.push_front(10);
    d.push_back(10);
    std::vector<int> v(10);
    std::cout << "Address of each element of vector\n";
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << "[" << std::dec << i << "]\t" << std::hex << "0x" << reinterpret_cast<void *>(&v[i]) << '\n';
    }
    std::cout << "Address of each element of dequeue\n";
    for (size_t i = 0; i < d.size(); i++)
    {
        std::cout << "[" << std::dec << i << "]\t" << std::hex << "0x" << reinterpret_cast<void *>(&d[i]) << '\n';
    }
    printDivider();

    // deques typically have large minimal memory cost
    std::array<int, 1> a1{0};
    std::vector<int> v1{0};
    std::deque<int> d1{0};
    std::cout << "Full size of each container consists of only one element:\n";
    std::cout << "\tstd::array: " << sizeof(a1) << '\n';
    std::cout << "\tstd::vector: " << sizeof(v1) << '\n';
    std::cout << "\tstd::deque: " << sizeof(d1) << '\n';
    printDivider();
}
