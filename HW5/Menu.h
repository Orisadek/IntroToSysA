/* Assignment C++: 3
   Author: Yuval Hendler
   Author: Ori Sadek
*/

#ifndef __MENU_H
#define __MENU_H


class Menu {
    int getInput()const; //return input
public:
    Menu();//constructor
    int mainMenu() const; // main menu of the mission
    double getLengthAndColor(char* obj_color, const char* shape, const char* length)const; //return the length and color of an object
    ~Menu();// destructor
};


#endif //_MENU_H
