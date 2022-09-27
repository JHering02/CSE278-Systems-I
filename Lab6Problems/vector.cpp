#include <iostream>
#include <vector>


void printVector(std::vector<int> vec, std::string name) {
  std::cout << "Vector " << name << ": ";
  for(int i = 0; i < vec.size(); ++i) {
    std::cout << vec.at(i) << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> vecA;
  std::vector<int> vecB;
  // Adding the vector values
  for(int i = 2; i <= 23; i += 3) {
    vecA.push_back(i);
  }
  printVector(vecA, "A");
  for(int i = 10; i <= 10000; i *= 10) {
    vecB.push_back(i);
  }
  printVector(vecB, "B");
  // Inserting the new vector values
  vecA.insert(vecA.begin(), 555);
  vecB.insert(vecB.begin(), vecA.begin(), vecA.begin() + 3);
  printVector(vecA, "A");
  printVector(vecB, "B");
  // Removing the vector values
  vecB.erase((vecB.end() - 2));
  vecA.erase(vecA.begin() + 1, (vecA.begin() + 5));
  printVector(vecB, "B");
  printVector(vecA, "A");
  // Calculating the sum
  int sum = vecB.front() + vecB.back();
  std::cout << vecB.front() << " + " << vecB.back() << " = " << sum << std::endl;
  return 0;
}