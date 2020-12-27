#ifndef POLY_POLYGON_H
#define POLY_POLYGON_H

#include "Shape.h"
#include <cmath>

class Polygon : public Shape {
public:
    Polygon(Point2D *points, int numPoints);

    virtual ~Polygon();

    virtual double calculateArea() const;

    virtual double calculatePerimeter() const;

protected:
    int n_points;
    Point2D *points_ptr;
};


#endif //POLY_POLYGON_H
