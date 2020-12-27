#include <iostream>
#include "Circle.h"

using namespace std;

Circle::Circle(Point2D point, double radius_length):radius(radius_length), center(point){
	cout << "Circle constructed. "<<endl;
}

Circle::~Circle(){
	cout << "Circle destructed. "<<endl;
}

double Circle::calculateArea() const {
    cout << "Circle::calculateArea() is Called!" << endl;
	return M_PI*this->radius*this->radius;
}

 double Circle::calculatePerimeter() const {
    cout << "Circle::calculatePerimeter() is Called!" << endl;
	return 2.0*M_PI*this->radius;
}


