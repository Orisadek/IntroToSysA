/* Assignment C++: 3
   Author: Yuval Hendler
   Author: Ori Sadek
*/

#include "Square.h"
#define NAME_SQAURE "Square"
#define EXCEPTION_LENGTH "Exception: The side must be positive\n"
#include <iostream>
using namespace  std;

Square::Square(char *color, double side_length) : Shape(color) { //constructor
    if(side_length < 0){
        throw EXCEPTION_LENGTH; // make sure side length larger than 0
    }
    this->side_length = side_length;
}

double Square::getPerimeter() const { //get perimeter
    return 4 * side_length;
}

double Square::getArea() const {
    return pow(side_length, 2); //get area
}
Square::~Square() {}// virtual destructor

void Square::draw() const { //draw the shape
    for(int i=0; i<(int)side_length; i++) {
        for(int j=0; j<(int)side_length; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

const char* Square::getName() const { // get the name
    return NAME_SQAURE;
}

double Square::getLengthProp()const { // get side_length
    return side_length;
}