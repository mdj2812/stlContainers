#pragma once

#include <deque>
#include <iostream>
#include <list>
#include <stack>

#include "Foo.hpp"
#include "Utility.hpp"

void stackDemo()
{
    // stack is a wrapper for underlying container
    std::deque<int> dq{1, 2, 3};
    std::cout << "Content of deque: ";
    printAll(dq.begin(), dq.end());
    {
        // Copy-constructs the underlying container dequeue with the contents of dq
        std::stack<int> c1(dq);
        std::cout << "Size of stack: " << c1.size() << '\n';
        c1.push(4);
        std::cout << "Size of stack after push: " << c1.size() << '\n';
        std::cout << "Size of deque after push: " << dq.size() << '\n';
        std::cout << "Content of deque after push via stack: ";
        printAll(dq.begin(), dq.end());
    }
    printDivider();

    // LIFO
    std::stack<Foo, std::list<Foo>> c2;
    c2.push(Foo(1, 2));
    c2.emplace(3, 4);
    std::cout << "Top of the stack: " << c2.top() << '\n';
    c2.pop();
    std::cout << "Top of the stack after the pop: " << c2.top() << '\n';
    printDivider();
}