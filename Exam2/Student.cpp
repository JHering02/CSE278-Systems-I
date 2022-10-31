#include "Student.h"

// Student class constructor
Student::Student() {
    this->first = "";
    this->last = "":
    this->gpa = 0.0;
}

Student::Student(string first, string last, double gpa) {
		this->first = first;    // first name
		this->last = last;      // last name
		this->gpa = gpa;        // grade point average
}

double Student::GetGPA() const {
		return gpa;
}

string Student::GetLast() const {
		return last;
}

string Student::GetFirst() const {
		return first;
}

// overload operator> implementation
Student Student::operator>(Student gpa1) {
    Student stu;
    if(gpa1.GetGPA() > gpa) {
        return gpa1;
    } else {
        stu.gpa = gpa;
        stu.first = first;
        stu.last = last;
        return stu;
    }
}