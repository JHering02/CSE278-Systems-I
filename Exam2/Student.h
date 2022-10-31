#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

// Class representing a student
class Student {
   public:
      Student();
      Student(string first, string last, double gpa);
      double GetGPA() const ;
      string GetLast() const ;
      string GetFirst() const ;
      Student operator>(Student gpa1);

   private:
      string first;  // first name
	   string last;   // last name
	   double gpa;    // grade point average
};

#endif