/* Assignment C++: 3
   Author: Yuval Hendler
   Author: Ori Sadek
*/

#ifndef __SQUARE_H
#define __SQUARE_H
#include "Shape.h"

using namespace std;

class Square : public Shape {
private:
    double side_length;
public:
    Square(char* color, double length);//constructor
    virtual double getPerimeter() const override; //get perimeter
    virtual double getArea() const override; //get area
    void draw() const;//draw the shape
    virtual const char* getName() const;// get the name
    virtual double getLengthProp() const; // get side_length
    virtual ~Square(); // virtual destructor
};
#endif //__SQUARE_H
