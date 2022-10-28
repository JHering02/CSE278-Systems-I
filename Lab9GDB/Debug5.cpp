#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;

int* maxelement(int* start, int* end){
       int* max;
       for(int *i = start; i <= end; ++i){
          if(*max < *i) {
            max = i;
          }
       }
      return max;
}

int main() {

  int data[] = {1, 3, 24, -1, 0, 16, 33, 45, 99, 77, 105, 12};
  std::cout << sizeof(data)/sizeof(data[0]) << std::endl;
  std::cout << std::max_element(std::begin(data),std::end(data)) << std::endl;
  std::cout << maxelement(&data[0], &data[(sizeof(data)/sizeof(data[0])) - 1]);
  std::sort(std::end(data) - 5, std::end(data));
  std::cout << "\n";
  for(int& val : data) {
    std::cout << val << std::endl;
  }

}