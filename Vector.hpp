#pragma once

#include <iostream>
#include <vector>

#include "Utility.hpp"

void vectorDemo()
{
    // the allocated memory usually does not change with the number of elements
    std::vector<int> a1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printAll(a1.cbegin(), a1.cend());
    std::cout << "Capacity of vector a1: " << a1.capacity() << " and its size: " << a1.size() << '\n';
    a1.resize(5);
    printAll(a1.cbegin(), a1.cend());
    std::cout << "content out of bound: ";
    for (int i = 5; i < 10; i++)
    {
        std::cout << *(a1.begin() + i) << ',';
    }
    std::cout << "\b \n";
    std::cout << "After resize, capacity of vector a1: " << a1.capacity() << " and its size: " << a1.size() << '\n';
    a1.shrink_to_fit();
    printAll(a1.cbegin(), a1.cend());
    std::cout << "content out of bound: ";
    for (int i = 5; i < 10; i++)
    {
        std::cout << *(a1.begin() + i) << ',';
    }
    std::cout << "\b \n";
    std::cout << "After shrink, capacity of vector a1: " << a1.capacity() << " and its size: " << a1.size() << '\n';
    a1.clear();
    printAll(a1.cbegin(), a1.cend());
    std::cout << "content out of bound: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << *(a1.begin() + i) << ',';
    }
    std::cout << "\b \n";
    std::cout << "After clear, capacity of vector a1: " << a1.capacity() << " and its size: " << a1.size() << '\n';
    printDivider();
}