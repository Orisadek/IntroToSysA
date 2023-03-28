/* Assignment C++: 3
   Author: Yuval Hendler
   Author: Ori Sadek
*/

#ifndef __SHAPE_H
#define __SHAPE_H
#include <iostream>
#include <string.h>
#include <math.h>                    //used in Inherited class

using namespace std;

class Shape {
private:
    char* color;
public:
    Shape(char* color); //constructor
    char* get_color() const; //get the color pointer
    virtual double getPerimeter() const = 0 ; //get perimeter - pure virtual
    virtual double getArea() const = 0 ;//get area  - pure virtual
    virtual ~Shape(); // virtual destructor 
    virtual const char* getName() const = 0;// get the name  - pure virtual
    virtual double getLengthProp() const = 0; // get LengthProp   - pure virtual
};
#endif