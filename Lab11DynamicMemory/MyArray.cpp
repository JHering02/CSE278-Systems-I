// MyArray implementation

#include <iostream>
#include <initializer_list>
#include <algorithm>

#include "MyArray.h"


// Implementation of each members and non-members

std::ostream& operator<<(std::ostream& os, MyArray const& v){
    // printing class
    os << "{";
    for(int i = 0; i < (int)v.asize - 1; ++i) {
        os << v.aptr[i];
        os << ", ";
    }
    os << v.aptr[v.asize - 1];
    os << "}";
    return os;
}

MyArray::MyArray(size_t size) {
    asize = size;
    aptr = new int[size];
}

MyArray::MyArray(std::initializer_list<int> list) {
    asize = list.size();
    aptr = new int[asize];
    std::copy(list.begin(), list.end(), aptr);
}

MyArray& MyArray::operator= (const MyArray& objCop) {
    if(this != &objCop) {
        asize = objCop.asize;
        delete aptr;
        aptr = new int[asize];
        for(int i = 0; i < (int)asize; ++i) {
            aptr[i] = objCop.aptr[i];
        }
    }
    std::cout << "MyArray copy assignment operator " << std::endl;
    return *this;
}

MyArray::MyArray(const MyArray& orig) {
    asize = orig.asize;
    aptr = new int[asize];
    for(int i = 0; i < (int)asize; ++i) {
        aptr[i] = orig.aptr[i];
    }
    std::cout << "MyArray copy constructor operator" << std::endl;
}


MyArray::~MyArray() {
    delete[] aptr;
    asize = 0;
    std::cout << "MyArray destructor" << std::endl;
}

void MyArray::resize(size_t newsize) {
    int* temp = new int[newsize];
    for(int i = 0; i < (int)asize; ++i) {
        temp[i] = aptr[i];
    }
    asize = newsize;
    delete[] aptr;
    aptr = temp;
}

int& MyArray::operator[](size_t index) {
    if(index > asize || index < 0) {
        throw std::out_of_range("Index is out of range.");
    } else {
        return aptr[index];
    }
}
