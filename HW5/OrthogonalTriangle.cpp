/* Assignment C++: 3
   Author: Yuval Hendler
   Author: Ori Sadek
*/

#include "OrthogonalTriangle.h"
#define NAME_TRIANGLE "OrthogonalTriangle"
#define EXCEPTION_LENGTH "Exception: The side must be positive\n"
using namespace std;

OrthogonalTriangle::OrthogonalTriangle(char* color,double side_length): Shape(color) {
    if (side_length < 0) {
        throw EXCEPTION_LENGTH; // make sure side length larger than 0
    }
    this->side_length = side_length;
}

double OrthogonalTriangle::getPerimeter() const {
    return sqrt(2 * side_length * side_length) + (side_length * 2);   //orthogonal triangle pythagoras sentence
}

double OrthogonalTriangle::getArea() const {
    return (side_length * side_length) / 2; //return area
}

void OrthogonalTriangle::draw() const {
    for(int i=0; i<(int)side_length; i++) { //draw triangle
        for(int j=0; j<=i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

OrthogonalTriangle::~OrthogonalTriangle(){ }
const char* OrthogonalTriangle::getName() const { //return the name
    return NAME_TRIANGLE;
}
double OrthogonalTriangle::getLengthProp()const { //return side length
    return side_length;
}