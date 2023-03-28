/* Assignment C++: 3
   Author: Yuval Hendler
   Author: Ori Sadek
*/
#ifndef __CIRCLE_H
#define __CIRCLE_H
#include "Shape.h"

class Circle : public Shape {
private:
    double radius;
public:
    Circle(char* color , double radius);//constructor
    virtual double getPerimeter() const;//get perimeter
    virtual double getArea() const;//get area
    virtual const char* getName() const;// get the name
    virtual double getLengthProp() const;// get radius
    virtual ~Circle();// virtual destructor
};


#endif 

