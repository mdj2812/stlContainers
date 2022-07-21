#include <forward_list>
#include <list>

void listDemo()
{
    // bi-direction
    std::list<int> mylist{1, 2, 3, 4};
    std::list<int>::iterator it = mylist.begin();
    ++it;
    --it;
    // it += 2;

    // Compared to std::forward_list this container is less space efficient
    std::list<int> list10{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::forward_list<int> forwardList10{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Consists of 10 elements, size of list: " << sizeof(list10) << ", size of forward_list: " << sizeof(forwardList10) << '\n';
    printDivider();
}