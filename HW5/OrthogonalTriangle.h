/* Assignment C++: 3
   Author: Yuval Hendler
   Author: Ori Sadek
*/


#ifndef __ORTHOGONALTRIANGLE_H
#define __ORTHOGONALTRIANGLE_H
#include "Shape.h"

class OrthogonalTriangle : public Shape {
private:
    double side_length;
public:
    OrthogonalTriangle(char* color, double length); //constructor
    void draw() const; //draw the shape
    virtual double getPerimeter()const; //get perimeter
    virtual double getArea()const; //get area
    virtual const char* getName() const; // get the name
    virtual double getLengthProp() const; // get side_length
    virtual ~OrthogonalTriangle(); // virtual destructor
};

#endif //__ORTHOGONALTRIANGLE_H
