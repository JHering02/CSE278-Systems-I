#ifndef CIRCLE_H
#define CIRCLE_H

#include<iostream>
using namespace std;

class Circle{
   
	private:
    double radius;
  
  public:
    // default constructor
    Circle();
    Circle(double newRadius);
    double getRadius() const;
    void setRadius(double r);
   
    //define operator+ (addition) as a member function
    Circle operator+ (Circle rds1);
   //define  operator- (substraction) as a member function
	Circle operator- (Circle rds1);
		
};
//define  operator< (less than) as a non-member function
bool operator< (Circle rds1, Circle rds2);
//define  operator> (less than) as a non-member function
bool operator> (Circle rds1, Circle rds2);
#endif
