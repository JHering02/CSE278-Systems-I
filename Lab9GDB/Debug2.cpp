#include<iostream>
const int SIZE = 5;
void printArray(int a[], int l) {
 if (l >= 0) {
   printArray(a, l-1);
   std::cout << a[l] << std::endl;
  }
}

int main() {
  int arr[SIZE]={10, 20, 30, 40, 50};
  printArray(arr, SIZE-1);
  return 0;
}
