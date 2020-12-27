/*
 * Shape.h
 * The header file for the class Shape
 */

#ifndef POLY_SHAPE_H
#define POLY_SHAPE_H

#include "Point2D.h"
#include <iostream>

class Shape {
public:


    Shape() {std::cout << "Constructing a Shape" << std::endl;};

    virtual ~Shape() {std::cout << "Shape destructed. " << std::endl;};

    virtual double calculateArea() const = 0;

    virtual double calculatePerimeter() const = 0;




        // Destructor, should be able to destroy the object according to its dynamic type (i.e. if it is a Circle, should be able to call the destructor of Circle).
        // outputs "Shape destructed."





        // calculateArea()
        // Pure virtual function. Compute the area of the shape.
        // returns a double value.





        // calculatePerimeter()
        // Pure virtual function. Compute the perimeter of the shape.
        // returns a double value.





        //------your code ends here------
    };

#endif //POLY_SHAPE_H
