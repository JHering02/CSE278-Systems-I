#include <iostream>
#include "Course.h"
using namespace std;

Student Course::FindStudentHighestGpa() const {
   double maxGpa = 0.0;
   Student best;
   for(int i = 0; i < roster.size(); ++i) {
        Student temp;
        temp = roster.at(i);
        if((temp) > (best)) {
            best = temp;
        }
   }
   return best;
}

void Course::AddStudent(Student s) {
	roster.push_back(s);
}

int Course::GetClassSize() const{
    return roster.size();    
}