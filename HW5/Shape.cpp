/* Assignment C++: 3
   Author: Yuval Hendler
   Author: Ori Sadek
*/

#include "Shape.h"
using namespace  std;
#define EXCEPTION_COLOR "Exception: color must be red green or blue\n"
#define  _CRT_SECURE_NO_WARNINGS


Shape::Shape(char * color){
    if (strcmp(color, "red") != 0 && strcmp(color, "green") != 0 &&
        strcmp(color, "blue") != 0){
        throw EXCEPTION_COLOR; // make sure the color is right
    }
    char* color_temp = new char[strlen(color)+1];
    strcpy(color_temp, color);
   // strcpy_s(color_temp, strlen(color) + 1, color);
    this->color = color_temp;
}
char* Shape::get_color() const { // return color
    return color;
}

Shape::~Shape() { // virtual destructor
    delete[] this->color;
}
