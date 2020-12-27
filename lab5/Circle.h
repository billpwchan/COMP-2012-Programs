#ifndef POLY_CIRCLE_H
#define POLY_CIRCLE_H

#include "Shape.h"
#include <cmath>

class Circle : public Shape {
public:

    Circle(Point2D point, double radius_length);

    virtual ~Circle();

    virtual double calculateArea() const;

    virtual double calculatePerimeter() const;


protected:
    double radius;
    Point2D center;
};


#endif //POLY_CIRCLE_H
