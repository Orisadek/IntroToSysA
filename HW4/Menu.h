/* Assignment C++: 2
   Author: Yuval Hendler
   Author: Ori Sadek
*/
#ifndef __MENU_H
#define __MENU_H
#include "Set.h"
class Menu {
    int showqueueMenu() const;
    int showSetMenu() const;
    void printSet(const Set& set, const int i)const;
    void addToSet(Set& set)const;
    void unionSet(const Set& set1, const Set& set2)const;
public:
    ~Menu();
    Menu();
    int mainMenu() const;
    int queueMenu() const;
    int setMenu() const;

};
#endif // __MENU_H
