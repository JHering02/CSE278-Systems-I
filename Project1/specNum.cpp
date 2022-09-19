// Copyright heringja, 13 September 2022, James Hering
// prints specific numbers between 1 and 31 according to the position of a bit.
// cpplint style checked
#include <iostream>

int main() {
  int choice = 0;
  std::cout << "Enter a bit position for a 5-bit length binary number:"
  << std::endl;
  do {
  std::cin >> choice;
  if (choice > 5 || choice < 1) {
    std::cout << "Out of range!!,"
              << " please enter a bit position between 1 and 5\n";
    continue;
  }
  } while (choice > 5 || choice < 1);
  int input = 1 << (choice - 1);
  std::cout << "The number list for the bit position ("
            << choice << ") equals 1 \n";
  for (int i = 1 ; i <= 31; ++i) {
    if ((input & i)) {
    std::cout << i << std::endl;
    }
  }
  std::cout << "End\n";
  return 0;
}
