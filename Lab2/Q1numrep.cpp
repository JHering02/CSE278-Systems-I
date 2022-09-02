// Program that shows an integer in various forms
// Copyright (c) JHering, 8/29/2022
#include <iostream>
#include <bitset>

int main() {
    unsigned int num;
    std::cout <<
    "Enter an unsigned integer number less than 2^16 in decimal: \n";
    std::cin >> std::dec >> num;
    // Print num in various bases
    std::cout
    << "Octal  :" << std::oct << num << std::endl
    << "Hex    :" << std::hex << num << std::endl
    << "Binary :" << std::bitset<16> (num) << std::endl;
    return 0;
}
