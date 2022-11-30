/*
Purpose: Course class test application
Date: October ,2022
by Z.Sevkli
*/
#include <iostream>
#include<fstream>
#include "Course.h"

int main(int argc, char * argv[])
{
  // Check if number of command-line arguments is 2 or not. If not, print a error message
  if(argc != 2) {
    std::cout << "command-line arguments error!!\nno outfile name was given";
    return 1;
  }
  // Create a ofstream object named outFile for the filename given in the command-line  
  std::ofstream outFile;
  // check if the file is able to open or not
  outFile.open(argv[1]);
    if (!outFile.is_open()) {
      std::cout << "Could not open file" << std::endl;
      return 1; // Error 
   }
  
  // Create Data Structure course object
  Course courseDStA("Data Structures", "A", 3);
  // add three students
  courseDStA.addStudent("Peter Jones");
  courseDStA.addStudent("Brian Smith");
  courseDStA.addStudent("Anne Kennedy");
    courseDStA.editStudent(2,"Anna Kennedy");
  // print course information with its student list
  std::cout << courseDStA << std::endl;
  // shrink student list
  courseDStA.shrinkCapacity();
  // Create Database Systems
  Course courseDStB("Data Structures", "B", 10);
  // add two students
  courseDStB.addStudent("Ahmad Nas");
  courseDStB.addStudent("Steve Smith");
  // print course info
  std::cout << courseDStB << std::endl;
  // merge two sections
  courseDStA += courseDStB;
  // print courses info
  std::cout << courseDStA << std::endl;
  std::cout << courseDStB << std::endl;
  // shrink student list
  courseDStA.shrinkCapacity();
  std::cout << courseDStA << std::endl;
  // add a student to database course
  courseDStA.addStudent("Khan Tran");
  // increase capacity
  courseDStA.increaseCapacity(3);
  courseDStA.addStudent("Khan Tran");
  std::cout << courseDStA << std::endl;
  // drop student
  courseDStA.dropStudent("Kaan Pease");
  std::cout << courseDStA<< std::endl;
  // create course using copy constructor
  Course courseDB(courseDStB);
  // change its name
  courseDB.setCourseName("Database Systems");
  courseDB.setSection("C");
  std::cout << courseDB << std::endl;
  // add student
  courseDB.addStudent("Ali Wattson");
  std::cout << courseDB << std::endl;
  std::cout << courseDStB << std::endl;
  // create copy object
  Course courseX("Special Topics", "X", 0);
  courseX = courseDB;
  courseX.setCourseName("Computer Network");
  std::cout << courseX << std::endl;
  // drop a student
  courseX.dropStudent("Ahmad Nas");
  std::cout << courseX << std::endl;
  std::cout << courseDB << std::endl;
  // drop all students from Computer Network
  courseX.dropStudent("Steve Smith");
  std::cout << courseX << std::endl;
  courseX.dropStudent("Ali Wattson");
  std::cout << courseX << std::endl;
  // write all course objects info to the file which was given as command-line argument
  outFile << courseDStA << courseDStB << courseDB << courseX;
  outFile.close();
  return 0;
}