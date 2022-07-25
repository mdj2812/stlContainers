#pragma once

#include <iostream>
#include <random>
#include <unordered_set>
#include <variant>

#include "Point.hpp"
#include "Utility.hpp"

struct MyHash
{
    std::size_t operator()(const Point &p) const noexcept
    {
        std::size_t h1 = std::hash<double>{}(p.x);
        std::size_t h2 = std::hash<double>{}(p.y);
        return h1 ^ (h2 << 1); // or use boost::hash_combine
    }
};

struct MyIntHash
{
    std::size_t operator()(const int v) const noexcept
    {
        constexpr size_t capacity = 100;
        return v % capacity;
    }
};

void unorderedSetDemo()
{
    // hash function
    std::cout << "Hash of key 1 = 0x" << std::hex << std::hash<int>{}(1) << '\n';
    std::cout << "Hash of key 1,000,000,000 = " << std::dec << std::hash<int>{}(1000000000) << '\n';
    std::cout << "Hash of key -1 = 0x" << std::hex << std::hash<int>{}(-1) << '\n';
    std::cout << "Hash of key \"abc\" = 0x" << std::hex << std::hash<std::string>{}("abc") << '\n';
    std::cout << "Hash of key 3.0f = 0x" << std::hex << std::hash<float>{}(3.0f) << '\n';
    std::cout << "Hash of key \'a\' = 0x" << std::hex << std::hash<char>{}('a') << '\n';
    std::cout << "Hash of key (1.0, 2.0) = 0x" << std::hex << MyHash{}(Point{1.0, 2.0}) << '\n';
    printDivider();

    // unordered_set with custom key type
    std::unordered_set<Point, MyHash> us1{Point{1.0, 2.0}, Point{3.0, 4.0}, Point{1.0, 2.0}, Point{1.0, 3.0}};
    printAll(us1.begin(), us1.end());
    std::cout << "Bucket number: " << us1.bucket_count() << ", load factor " << us1.load_factor() << '\n';

    // load factor after 1000 insertions
    std::random_device r;
    // Choose a random mean between 1 and 6
    std::mt19937 rng(r());
    std::uniform_real_distribution<double> dist(-1000, 1000);
    for (size_t i = 0; i < 1000; i++)
    {
        us1.emplace(Point{dist(rng), dist(rng)});
    }
    std::cout << "Randomly added 1000 points.\n";
    std::cout << "Bucket number: " << us1.bucket_count() << ", load factor " << us1.load_factor() << '\n';

    // buckets
    std::unordered_set<int, MyIntHash> us2;
    for (size_t i = 0; i < 1000; i++)
    {
        us2.emplace(i);
    }
    auto bucketIdx = us2.bucket(40);
    std::cout << "Bucket index of key 40: " << bucketIdx << ", whose size is: " << us2.bucket_size(bucketIdx);
    printDivider();

    // load factor cap
    std::unordered_set<int> us3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Default load factor max: " << us3.max_load_factor() << ". Current load factor" << us3.load_factor() << ",bucket number: " << us3.bucket_count() << '\n';
    us3.max_load_factor(0.5);
    us3.emplace(10);
    std::cout << "Set load factor max to: " << us3.max_load_factor() << ". Current load factor" << us3.load_factor() << ",bucket number: " << us3.bucket_count() << '\n';
    printDivider();
}