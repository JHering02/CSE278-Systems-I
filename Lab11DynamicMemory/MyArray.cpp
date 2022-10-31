// MyArray implementation

#include <iostream>
#include <initializer_list>
#include <algorithm>

#include "MyArray.h"

// Write the implementation of each members and non-members
MyArray::MyArray(size_t size) {
    asize = size;
    aptr = new int[size];
}

MyArray::MyArray(std::initializer_list<int> list) {
    asize = list.size();
    aptr = new int[asize];
    std::copy(list.begin(), list.end(), aptr);
}

void MyArray::resize(size_t newsize) {
    int* temp = new int[newsize];
    for(int i = 0; i < asize; ++i) {
        temp[i] = aptr[i];
    }
    asize = newsize;
    delete[] aptr;
    aptr = temp;
}

int& MyArray::operator[](size_t index) {
    
}
