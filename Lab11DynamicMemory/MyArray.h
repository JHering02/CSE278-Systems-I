// MyArray Class decleration

#pragma once
#include <iostream>
#include <initializer_list>

class MyArray {
    // friend operator<<
  private:
    size_t asize;
    int * aptr;  

  public:
    // two constructors
    MyArray(size_t size);
    MyArray(std::initializer_list<int> list);
    // size()
    size_t size() {return asize;}
    // resize()
    void resize(size_t newsize);
    // operator[]
    int& operator[](size_t index);
    
};