#pragma once

#include <iostream>
#include <map>
#include <string>

#include "Utility.hpp"

class Bar
{
public:
    Bar(double d, std::string s) : mD(d), mS(s) {}
    Bar(const Bar &) = delete;
    Bar(Bar &&) = delete;

    std::partial_ordering operator<=>(const Bar &other) const
    {
        return mD <=> other.mD;
    }

    double getD() const { return mD; }
    std::string getS() const { return mS; }

private:
    double mD;
    std::string mS;
};

std::ostream &operator<<(std::ostream &os, const Bar &bar)
{
    os << "(" << bar.getD() << ", " << bar.getS() << ")";
    return os;
}

void mapDemo()
{
    // element access
    std::map<std::string, int> m1{{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};
    printAll(m1.begin(), m1.end());

    std::cout << "Try to get access to non-existing element with at():\n";
    try
    {
        m1.at("SSD");
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Exception thrown: " << e.what() << '\n';
    }

    m1["CPU"] = 25; // update an existing value
    m1["SSD"] = 30; // insert a new value
    std::cout << "After modification and insertion:\n";
    printAll(m1.begin(), m1.end());
    printDivider();

    // insert_or_assign <=> operator[]
    m1.insert_or_assign("GPU", 30);         // update an existing value
    m1.insert_or_assign("MOTHERBOARD", 10); // insert a new value
    std::cout << "After insert_or_assign:\n";
    printAll(m1.begin(), m1.end());
    printDivider();

    // emplace is the only way for non-copyable and non-moveable objects
    std::map<Bar, int> m2;
    // try_emplace will always move or copy the key value
    // m2.try_emplace({1, "hello"}, 1);
    // the only way to solve this is by using piecewise construction constructor
    m2.emplace(std::piecewise_construct, std::forward_as_tuple(1, "hello"), std::forward_as_tuple(1));
    printAll(m2.begin(), m2.end());
    printDivider();
}