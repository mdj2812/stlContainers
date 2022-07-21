#pragma once

#include <iostream>

void printDivider()
{
    std::cout << "\n*******************************************\n";
}

template <typename InputIt>
void printAll(const InputIt begin, const InputIt end)
{
    if (begin == end)
    {
        std::cout << "{}\n";
        return;
    }
    std::cout << "{";
    for (auto it = begin; it != end; ++it)
    {
        std::cout << std::dec << *it << ",";
    }
    std::cout << "\b}\n";
}

void hexdump(void *ptr, int buflen)
{
    unsigned char *buf = (unsigned char *)ptr;
    int i, j;
    for (i = 0; i < buflen; i += 16)
    {
        printf("%06x: ", i);
        for (j = 0; j < 16; j++)
            if (i + j < buflen)
                printf("%02x ", buf[i + j]);
            else
                printf("   ");
        printf(" ");
        for (j = 0; j < 16; j++)
            if (i + j < buflen)
                printf("%c", isprint(buf[i + j]) ? buf[i + j] : '.');
        printf("\n");
    }
}
