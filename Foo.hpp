#pragma once

#include <iostream>

class Foo
{
public:
    float x, y;

    // Parameterized Constructor
    Foo(float x, float y)
        : x(x), y(y)
    {
    }

    ~Foo()
    {
        std::cout << "(" << x << ", " << y << ")"
                  << "destroyed\n";
    }

    // Copy Constructor
    Foo(const Foo &Foo)
        : x(Foo.x), y(Foo.y)
    {
        std::cout << "Copied\n";
    }
};

std::ostream &operator<<(std::ostream &os, const Foo &foo)
{
    os << "(" << foo.x << ", " << foo.y << ")";
    return os;
}
