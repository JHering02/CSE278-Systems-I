// Copyright ZSevkli 2022
// MyArray Program

#include <iostream>
#include <stdexcept>
#include "MyArray.h"

int main() {
    MyArray ints1{1, 2, 3, 4};
    MyArray ints2{10, 20, 30};
    ints2.resize(5);
    ints2[4] = 40;
    // print ints1 size and content
    std::cout << "ints1 size: " <<ints1.size() << std::endl;
    std::cout << "ints1 content: " <<ints1 << std::endl;

    // print ints2 size and content
    std::cout << "ints2 size: " <<ints2.size() << std::endl;
    std::cout << "ints2 content: " <<ints2 << std::endl;

    
    // Part2
    // create MyArray ints3 by copying ints2
    MyArray ints3(ints2);
 
    // print ints3 size and content
    std::cout << "ints3 size: " <<ints3.size() << std::endl;
    std::cout << "ints3 content: " <<ints3 << std::endl;

    ints3[0] = 111;
    std::cout << "Check the ints2 and ints3 result: Is this what you expected?? " << std::endl;
    std::cout << "ints2 content: " << ints2 << std::endl;
    std::cout << "ints3 content: " << ints3 << std::endl;

    // Part3
    // use overloaded copy assignment (=) operator
    MyArray ints4 = {7, 77, 777};
    std::cout << "Assigning ints1 to ints4" << std::endl;
    ints4 = ints1;

    std::cout << "ints1:" << ints1 << std::endl;
    std::cout << "ints4:" << ints4 << std::endl;
    ints1[1] = ints4[0]+777;
    std::cout << "Check the ints1 and ints4 result: Is this what you expected?? " << std::endl;
    std::cout << "ints1 content: " <<ints1 << std::endl;
    std::cout << "ints4 content: " <<ints4 << std::endl;

    return 0;
}