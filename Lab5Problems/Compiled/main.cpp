#include "functions.h"
#include <iostream>

int main() {
    // Test 1
    std::cout << "400.4 300.4 200.5 100.44" << std::endl;
    std::cout << "Order: " << CheckOrder(400.4, 300.4, 200.5, 100.44) << std::endl;
    // Test 2
    std::cout << "100 200 300 400" << std::endl;
    std::cout <<"Order: " << CheckOrder(100, 200, 300, 400) << std::endl;
    // Test 3
    std::cout << "100 300 300 400" << std::endl;
    std::cout <<"Order: " << CheckOrder(100, 300, 300, 400) << std::endl;
    // Test 4
    std::cout << "100 500 300 400" << std::endl;
    std::cout << "Order: " << CheckOrder(100, 500, 300, 400) << std::endl;
    // Test 5
    std::cout << " a B s Z" << std::endl;
    std::cout <<"Order: " << CheckOrder('a', 'B', 's', 'Z') << std::endl;
    // Test 6
    std::cout << " a b s z" << std::endl;
    std::cout <<"Order: " << CheckOrder('a', 'b', 's', 'z') << std::endl;
    // Test 7
    std::cout << " sat sat mat hat" << std::endl;
    std::cout <<"Order: " << CheckOrder("sat", "sat", "mat", "hat") << std::endl;
    // Test 8
    std::cout << " live long and prosper" << std::endl;
    std::cout <<"Order: " << CheckOrder("live", "long", "and", "prosper") << std::endl;
   
   return 0;
}