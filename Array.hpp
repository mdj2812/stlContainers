#include <array>
#include <iostream>
#include <memory>
#include <tuple>

template <typename T>
void printArray(const T *begin, const T *end)
{
    std::cout << "{";
    for (auto it = begin; it != end; ++it)
    {
        std::cout << *it << ",";
    }
    std::cout << "\b}\n";
}

void DumpMem(const void *mem, unsigned int n)
{
    const char *p = reinterpret_cast<const char *>(mem);
    for (unsigned int i = 0; i < n; i++)
    {
        std::cout << std::hex << int(p[i]) << " ";
    }
    std::cout << std::endl;
}

void arrayDemo()
{
    // the same semantics as a struct holding a C-style array T[N] as its only non-static data member
    int cStyleArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 10> containerArray = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "C-style array size: " << sizeof(cStyleArray) << '\n';
    std::cout << "std::array size: " << sizeof(containerArray) << '\n';
    std::cout << "C-style array memory range: [" << static_cast<void *>(cStyleArray) << ", " << static_cast<void *>(&cStyleArray[10]) << "]\n";
    std::cout << "C-style array memdump:\n";
    DumpMem(cStyleArray, sizeof(cStyleArray));
    std::cout << "std::array memory range: [" << static_cast<void *>(&containerArray) << ", " << static_cast<void *>(&containerArray[10]) << "]\n";
    std::cout << "std::array memdump:\n";
    DumpMem(&containerArray, sizeof(containerArray));

    // An array can also be used as a tuple of N elements of the same type.
    std::array<int, 3> asTuple{1, 2, 3};
    std::cout << "Get as a tuple: std::get<0> = " << std::get<0>(asTuple) << '\n';
    const auto [int1, int2, int3] = asTuple;
    std::cout << "structured binding: [" << int1 << ", " << int2 << ", " << int3 << "]\n";

    // moveable but ...
    auto target = std::move(containerArray);
    std::cout << "target: ";
    printArray<int>(target.begin(), target.end());
    std::cout << "source: ";
    printArray<int>(containerArray.begin(), containerArray.end());
    std::array<std::string, 3> stringArray = {"abcd", "1234", "+-*/"};
    auto targetStringArray = std::move(stringArray);
    std::cout << "target: ";
    printArray<std::string>(targetStringArray.begin(), targetStringArray.end());
    std::cout << "source: ";
    printArray<std::string>(stringArray.begin(), stringArray.end());

    // deduction guide for array creation (since C++17)
    std::array deductionArray{3.0, 1.0, 4.0}; // -> std::array<double, 3>
    static_assert(std::is_same_v<decltype(deductionArray), std::array<double, 3>>);

    // to_array examples
    // copies a string literal
    auto a1 = std::to_array("foo");
    static_assert(a1.size() == 4);
    printArray(a1.begin(), a1.end());

    // deduces both element type and length
    auto a2 = std::to_array({0, 2, 1, 3});
    static_assert(std::is_same_v<decltype(a2), std::array<int, 4>>);

    // deduces length with element type specified
    // implicit conversion happens
    auto a3 = std::to_array<long>({0, 1, 3});
    long a3InC[] = {0, 1, 3};
    static_assert(std::is_same_v<decltype(a3), std::array<long, 3>>);

    auto a4 = std::to_array<std::pair<int, float>>(
        {{3, .0f}, {4, .1f}, {4, .1e23f}});
    static_assert(a4.size() == 3);

    // creates a non-copyable std::array
    auto a5 = std::to_array({std::make_unique<int>(3)});
    static_assert(a5.size() == 1);

    // error: copying multidimensional arrays is not supported
    // char s[2][6] = { "nice", "thing" };
    // auto a6 = std::to_array(s);
}