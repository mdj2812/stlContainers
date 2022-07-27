#include "Array.hpp"
#include "Deque.hpp"
#include "ForwardList.hpp"
#include "List.hpp"
#include "Map.hpp"
#include "Multiset.hpp"
#include "MyContainer.hpp"
#include "PriorityQueue.hpp"
#include "Queue.hpp"
#include "Set.hpp"
#include "Stack.hpp"
#include "UnorderedMultiSet.hpp"
#include "UnorderedSet.hpp"
#include "Vector.hpp"

int main(int, char **)
{
    rangeBasedLoopDemo();
    arrayDemo();
    vectorDemo();
    dequeDemo();
    forwardListDemo();
    listDemo();
    setDemo();
    multisetDemo();
    mapDemo();
    unorderedSetDemo();
    unorderedMultiSet();
    stackDemo();
    queueDemo();
    priorityQueueDemo();
}
