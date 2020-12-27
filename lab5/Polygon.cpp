#include <iostream>
#include "Polygon.h"

using namespace std;

Polygon::Polygon(Point2D *points, int numPoints): n_points(numPoints) {
    points_ptr = new Point2D[this->n_points];
    for (int i=0;i<this->n_points;i++){
        Point2D* temp = new Point2D(points[i]);
        points_ptr[i]=*temp;
        delete temp;
    }
    cout << "Polygon constructed. " << endl;
}

Polygon::~Polygon() {
    delete [] this->points_ptr;
    cout << "Polygon destructed. " << endl;
}

double Polygon::calculateArea() const {
    double area = 0;
    for (int i = 0; i < n_points - 1; i++) {
        area += this->points_ptr[i].getX() * this->points_ptr[i + 1].getY();
        area -= this->points_ptr[i + 1].getX() * this->points_ptr[i].getY();
    }
    area += this->points_ptr[n_points - 1].getX() * this->points_ptr[0].getY();
    area -= this->points_ptr[0].getX() * this->points_ptr[n_points - 1].getY();

    cout << "Polygon::calculateArea() is Called!" << endl;
    return abs(area) / 2.0;
}

double Polygon::calculatePerimeter() const {
    double perimeter = 0;
    for (int i = 0; i < n_points - 1; i++) {
        perimeter += this->points_ptr[i].distance(this->points_ptr[i + 1]);
    }
    perimeter += this->points_ptr[n_points - 1].distance(this->points_ptr[0]);
    cout << "Polygon::calculatePerimeter() is Called!" << endl;
    return perimeter;
}


