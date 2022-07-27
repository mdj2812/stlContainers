#pragma once

#include <iostream>
#include <vector>

#include "Foo.hpp"
#include "Utility.hpp"

// constexpr bool testVector(int n)
// {
//     std::vector<int> vec(n, 1);
//     int sum = 0;
//     for (auto &elem : vec)
//         sum += elem;
//     return n == sum;
// }

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

    // push_back vs emplace_back
    std::vector<Foo> foos;
    foos.reserve(2);
    std::cout << "push_back:";
    foos.push_back(Foo(1, 2));
    std::cout << "emplace_back:";
    foos.emplace_back(1, 2);
    printDivider();

    // insert() applied to a vector will invalidate any iterators or references to elements of the vector
    std::vector<int> myvector(3, 100);
    std::vector<int>::iterator it;

    std::cout << "myvector contains: ";
    printAll(myvector.cbegin(), myvector.cend());

    it = myvector.begin();
    std::cout << "it before insertion: " << *it << '\n';

    myvector.insert(it, 2, 300);

    std::cout << "it after insertion: " << *it << '\n';

    // "it" no longer valid, get a new one:
    it = myvector.begin();

    std::cout << "myvector contains: ";
    printAll(myvector.cbegin(), myvector.cend());
    printDivider();

    // std::vector under constexpr context. Not supported by the compiler yet
    // static_assert(testVector(10));
}