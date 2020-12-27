#include "Quadrilateral.h"
#include <iostream>
#include <cmath>

using namespace std;

//Must call the super class constructor via member initialization list.
//If not, will call the default constructor of super class.
Quadrilateral::Quadrilateral(const Point2D points[], int numPoints):Polygon(points, numPoints){
	if (numPoints != 4) {
        cout << "Illegal! Number of points should be 4" << endl;
		if (this->numPoints != 0) {
			delete [] this->points;
		}
		numPoints = 0;
		this->points = NULL;
		return;
	}
    cout << "Initialized by Quadrilateral's other constructor" << endl;
}

Quadrilateral::~Quadrilateral() {
	cout << "Quadrilateral's destructor!" << endl;
}


void Quadrilateral::print() const {
	cout << "Quadrilateral's center: ";
    this->center().print();
    cout << endl;
	cout << "Quadrilateral's perimeter: "<<perimeter()<<endl;
	cout << "Quadrilater's area: "<<area()<<endl;
}



Point2D Quadrilateral::center() const {
	double xValue = 0, yValue = 0;
	for (int i = 0; i < this->numPoints; i++) {
		xValue += this->points[i].getX();
		yValue += this->points[i].getY();
	}
	return Point2D(xValue / this->numPoints, yValue / this->numPoints);
}


double Quadrilateral::perimeter() const {
	double perimeter = 0;
	perimeter += this->points[0].distance(this->points[1]);
	perimeter += this->points[1].distance(this->points[2]);
	perimeter += this->points[2].distance(this->points[3]);
	perimeter += this->points[3].distance(this->points[0]);
	return perimeter;
}


double Quadrilateral::area() const{
	double result=0;
	for (int i=0;i<this->numPoints;i++){
		if (i==3){
			result+=this->points[i].getX()*this->points[i-3].getY();
			result-=this->points[i-3].getX()*this->points[i].getY();
		}else{
			result+=this->points[i].getX()*this->points[i+1].getY();
			result-=this->points[i+1].getX()*this->points[i].getY();
		}
	}
    result=abs(result);
	return result/2.0;
}
