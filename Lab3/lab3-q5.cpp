// Copyright (c) James Hering 9/2/2022
#include <iostream>
// #include <bitset>
int main() {
    u_int16_t number;
    std::cout << "Input a short integer\n";
    std::cin >> number;
    u_int16_t mask = 1 << 1;
    u_int16_t resultLSB = number & mask;
    u_int16_t resultMSB = number ^ mask;
    if (resultLSB == 0) {std::cout << "Second least significant bit is 0\n";
    } else {std::cout << "Second least significant bit is 1\n";}
    if (resultMSB == 0) {std::cout << "Most significant bit is 0\n";
    } else {std::cout << "Most significant bit is 1\n";}
    return 0;
}
