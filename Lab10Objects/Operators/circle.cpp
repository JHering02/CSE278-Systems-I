#include "circle.h"
using namespace std;

Circle::Circle(){
	radius=1;

}

Circle::Circle(double newRadius){
	this->setRadius(newRadius);
}
double Circle::getRadius() const{
	return radius;
}
void Circle::setRadius(double r){
  if (r>0)
        radius=r;
	else
	   radius=0;
}

//define operator+ (addition) as a member function
Circle Circle::operator + (Circle rds1) {
    Circle res;
    double newRds = (radius + rds1.getRadius());
    res.setRadius(newRds);
    return res;
}
//define  operator- (substraction) as a member function
Circle Circle::operator - (Circle rds1) {
    Circle res;
    double newRds = (radius - rds1.getRadius());
    if(radius > rds1.getRadius()) {
        res.setRadius(newRds);
    } else {
        res.setRadius(0);
    }
    return res;
}

// implement operator< as a non member
bool operator< (Circle rds1, Circle rds2) {
    if(rds1.getRadius() < rds2.getRadius()) {
        return true;
    } else {
        return false;
    }
}
// implement operator> as a non member
bool operator> (Circle rds1, Circle rds2) {
    if(rds1.getRadius() > rds2.getRadius()) {
        return true;
    } else {
        return false;
    }
}

