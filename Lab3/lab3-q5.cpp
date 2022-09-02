// Copyright (c) James Hering 9/2/2022
#include <iostream>
// #include <bitset>

int main()
{
    u_int16_t number;
    std::cin >> number;
    u_int16_t mask = 1 << 1;
    u_int16_t result = number & mask;
    if (result == 0)
    {
        std::cout << "Second least significant bit is 0";
    }
    else
    {
        std::cout << "Second least significant bit is 1";
    }
    return 0;
}