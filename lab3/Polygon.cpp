#include "Polygon.h"
#include <iostream>

using namespace std;

Polygon::Polygon(): numPoints(0), points(NULL){
	cout << "Initialized by Polygon's default constructor"<<endl;
}

Polygon::Polygon(const Polygon& s): numPoints(s.numPoints){
	this->points=new Point2D[s.numPoints];
	for (int i=0;i<s.numPoints;i++){
		this->points[i]=s.points[i];
	}
	cout << "Initialized by Polygon's other constructor"<<endl;
}


Polygon::Polygon(const Point2D points[], int numPoints):numPoints(numPoints){
	cout << "Initialized by Polygon's other constructor"<<endl;
	this->points = new Point2D[numPoints];
	for (int i=0;i<numPoints;i++){
		this->points[i]=points[i];
	}
}

Polygon::~Polygon(){
	delete [] points;
	cout << "Polygon's destructor!"<<endl;
}

void Polygon::print() const {
	if (this->numPoints==0){
		cout << "The Polygon is empty!"<<endl;
		return;
	}
	cout << "Number of points: "<<this->numPoints<<endl;
	cout << "Points: ";
	for (int i=0;i<this->numPoints;i++){
        this->points[i].print();
	}
	cout << endl;


}
