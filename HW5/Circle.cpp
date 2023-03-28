/* Assignment C++: 3
   Author: Yuval Hendler
   Author: Ori Sadek
*/

#include "Circle.h"
#define _USE_MATH_DEFINES
#include <math.h>
#define NAME_CIRCLE "Circle"
#define EXCEPTION_LENGTH "Exception: The radius must be positive\n"

Circle::Circle(char *color, double radius): Shape(color) {
    if (radius < 0) {
        throw EXCEPTION_LENGTH; // make sure radius larger than 0
    }
    this->radius = radius; //constructor
}

double Circle::getLengthProp()const { //return radius
    return radius;
}

double Circle::getPerimeter() const { //return perimeter
    return 2 * M_PI * radius;
}

double Circle::getArea() const { //return area
    return M_PI * pow(radius,2);
}
Circle::~Circle() {}// virtual destructor

const char* Circle::getName() const {  //return the name
    return NAME_CIRCLE;
}