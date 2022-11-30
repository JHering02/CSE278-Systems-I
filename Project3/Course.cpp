/*
Purpose: The API for a course class
Date: 11/14/2022
by James Hering
*/

#include <iostream>
#include <iomanip>
#include "Course.h"


Course::Course(const std::string& courseName, const std::string& section, size_t capacity) {
  this->courseName = courseName;
  this->section = section;
  this->capacity = capacity;
  this->numberOfStudents = 0;
  this->students = new std::string[capacity];
  std::cout << courseName + "-" + section + " has been created!" << std::endl;
}

Course::~Course() {
  std::cout << courseName + "-" + section + " has been deleted!" << std::endl;
  delete[] students;
  capacity = 0;
  numberOfStudents = 0;
}

Course::Course(const Course& orig) {
  courseName = orig.courseName;
  section = orig.section;
  numberOfStudents = orig.numberOfStudents;
  capacity = orig.capacity;
  students = new std::string[capacity];
  for(int i = 0; i < (int)numberOfStudents; ++i) {
      students[i] = orig.students[i];
  } 
  std::cout << "New " << courseName + "-" + section + " has been created by the copy constructor!\n";
}

Course& Course::operator= (const Course& objCop) {
    std::cout << "The content of " << objCop.courseName
              << "-" << objCop.section << " was copied to "
              << courseName << "-" << section << " using operator=" << std::endl;
    if(this != &objCop) {
        courseName = objCop.courseName;
        section = objCop.section;
        numberOfStudents = objCop.numberOfStudents;
        capacity = objCop.capacity;
        delete[] students;
        students = new std::string[capacity];
        for(int i = 0; i < (int)numberOfStudents; ++i) {
            students[i] = objCop.students[i];
        }
    }
    return *this;
}
       
void Course::setCourseName(std::string name) {
  std::cout << "Course name " << courseName << "-" << section 
            << "has been changed to " << name << "-" << section << std::endl;
  courseName = name;
}

std::string Course::getCourseName() const {
  return courseName;
}

void Course::setSection(std::string section) {
  std::cout << "Course section " << courseName << "-" << this->section 
            << "has been changed to " << section << std::endl;
  this->section = section;
}

std::string Course::getSection() const {
  return section;
}

void Course::addStudent(const std::string& name) {
  if(numberOfStudents == capacity) {
    std::cout << "The course" + courseName + "-" + section + 
    " has reached maximum capacity! You need to increase the capacity!!\n";
  } else {
    students[numberOfStudents] = name;
    ++numberOfStudents;
    std::cout << name << " was added to " 
              << courseName << "-" << section << " successfully\n";
  }
}
  
void Course::editStudent(size_t index,std::string newname) {
  if(index > numberOfStudents) {
    throw std::out_of_range("Index out of range");
  } else {
    std::string temp = students[index];
    students[index] = newname;
    std::cout << "The name of the student " + temp + " has been changed to " + students[index] << std::endl;
  }
}

void Course::dropStudent(const std::string& name) {
  int temp = numberOfStudents;
  for(int i = 0; i < (int)numberOfStudents; ++i) {
    if(students[i].compare(name) == 0) {
      std::string temp = students[i];
      students[i] = students[numberOfStudents - 1];
      numberOfStudents--;
      std::cout << "Student: " << name << " dropped the course" << courseName << "-" << section;
    }
  }
  if(temp == (int)numberOfStudents) {
    std::cout << "Student: " << name << " was not found!";
  }
}

size_t Course::getNumberOfStudents() const {
  return numberOfStudents;
}

size_t Course::getCourseCapacity()const {
  return capacity;
}

void Course::shrinkCapacity() {
  if(capacity > numberOfStudents) {
    std::string* temp = new std::string[numberOfStudents];
    for(int i = 0; i < (int)numberOfStudents; ++i) {
        temp[i] = students[i];
    }
    capacity = numberOfStudents;
    delete[] students;
    students = temp;
    std::cout << "The capacity of " + courseName + "-" + section + 
    " is now equal to the number of students";
  } else {
    std::cout << "No need to shrink !! Capacity is equal to the number of students for " + 
    courseName + "-" + section;
  }
}

void Course::increaseCapacity(size_t inc) {
  std::string* temp = new std::string[capacity + inc];
  for(int i = 0; i < (int)numberOfStudents; ++i) {
        temp[i] = students[i];
  }
  capacity += inc;
  delete[] students;
  students = temp;
  std::cout << "The capacity of " << courseName << "-" << section << 
  " has been increased by " << inc;
}

std::string Course::getStudents(size_t index) {
  if(index > numberOfStudents) {
    throw std::out_of_range("Index out of range");
  } else {
    return students[index];
  }
}

Course& Course::operator+= (Course& cour1)  {
  capacity = (capacity + cour1.capacity);
  std::string* temp = new std::string[capacity];
  for(int i = 0; i < (int)numberOfStudents; ++i) {
    temp[i] = students[i];
  }
  int j = 0;
  for(int i = (int)numberOfStudents; i < (int)(numberOfStudents + cour1.numberOfStudents); ++i) {
    temp[i] = cour1.students[j];
    j++;
  }
  numberOfStudents = (numberOfStudents + cour1.numberOfStudents);
  students = temp;
  section = (section + cour1.section);
  std::cout << "Two courses were merged under the " << courseName 
            << "-" << section << std::endl;
  return *this;
}

std::ostream& operator<< (std::ostream& os, Course const& v) {
  os << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  os << std::setw(11) << std::left << "Course Name" << ": " << v.courseName << "\n";
  os << std::setw(11) << std::left << "Section" << ": " << v.section << "\n";
  os << std::setw(11) << std::left << "Capacity" << ": " << v.capacity << "\n";
  os << std::setw(11) << std::left << "#ofStudents" << ": " << v.numberOfStudents << "\n";
  os << "---------Student List------------\n";
  if(v.numberOfStudents) {
     for(int i = 0; i < (int)v.numberOfStudents; ++i) {
       os << (i + 1) << ". " << std::setw(13) << v.students[i] << "\n"; 
     }
  } else {
     os << "(no students to list)\n";
  }
  return os;
}
