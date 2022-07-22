#pragma once
#include <forward_list>
#include <iostream>

#include "Utility.hpp"

void forwardListDemo()
{
    // The insertion does not invalidate any iterators or references to elements of the forward_list
    std::forward_list<int> mylist{1, 2, 3, 4};
    std::forward_list<int>::iterator it = mylist.begin();
    ++it;
    // --it;
    // it += 2;

    std::cout << "mylist contains: ";
    printAll(mylist.cbegin(), mylist.cend());

    it = mylist.begin();
    std::cout << "it before insertion: " << *it << '\n';

    mylist.insert_after(it, 100);
    mylist.push_front(7);

    std::cout << "it after insertion: " << *it << '\n';
    printAll(mylist.cbegin(), mylist.cend());
    printDivider();

    // merge without sort
    std::forward_list<int> list1 = {5, 9, 1, 3, 3};
    std::forward_list<int> list2 = {8, 7, 2, 3, 4, 4};

    auto list3 = list1;
    list3.merge(list2);
    std::cout << "Result list without sort:";
    printAll(list3.begin(), list3.end());

    list1.sort();
    list2.sort();
    list1.merge(list2);
    std::cout << "Result list with sort:";
    printAll(list1.begin(), list1.end());
    printDivider();
}