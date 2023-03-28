/* Assignment C++: 2
   Author: Yuval Hendler
   Author: Ori Sadek
*/
#include "Menu.h"
#include "Set.h"
#include "myQueue.h"
#include <iostream>
using namespace std;
#define ERROR "Invalid Selection.\n"
#define BYE "Goodbye!\n"


Menu::Menu() {}
Menu::~Menu() {};

int Menu::mainMenu() const {
    int fl = 1;
    while (fl) {
        int input;
        cout << "(1) Set Menu\n";
        cout << "(2) Integer Queue Menu\n";
        cout << "(3) Exit\n";
        cin >> input;
        switch (input) {
        case 1:
            setMenu();
            break;
        case 2:
            queueMenu();
            break;
        case 3:
            fl = 0;
            break;
        default:
            cout << ERROR;
        }
    }
    cout << BYE;
    return 0;
}




int Menu::showSetMenu() const {
    int input;
    cout << "***Welcome to Set Menu ***\n";
    cout << "To select an item, enter\n";
    cout << "1 Show set 1\n";
    cout << "2 Show set 2\n";
    cout << "3 add element to set 1\n";
    cout << "4 add element tp set 2\n";
    cout << "5 Show set1 U set 2 (union)\n";
    cout << "6 to exit\n";
    cin >> input;
    return input;
}

void Menu::printSet(const Set& set, const int i)const {
    if (set.getCurrentSize() == 0) {
        cout << "Set" << i << " is empty"<<endl;
    }
    else {
        cout << set;
    }
  
}

void Menu::addToSet( Set& set)const {
    int input = 0;
    cout << "Give a number: ";
    cin >> input;
    set += input;
}

void Menu::unionSet(const Set& set1, const Set& set2)const {
    Set s = set1 + set2;
    if (s.getCurrentSize() == 0) {
        cout << "empty union" << endl;
    }
    else {
        cout << s;
    }
    
}


int Menu::setMenu() const {
    Set set1, set2;
    int fl = 1;
    while (fl) {
        int input = showSetMenu();;
        switch (input) {
        case 1:
            printSet(set1, 1);
            break;
        case 2:
            printSet(set2, 2);
            break;
        case 3:
            addToSet(set1);
            break;
        case 4:
            addToSet(set2);
            break;
        case 5:
            unionSet(set1, set2);
            break;
        case 6:
            fl = 0;
            break;
        default:
            cout << ERROR;
        }
    }
    return 0;
}

int Menu::showqueueMenu() const {
    int input;
    cout << "*** Welcome to Queue Menu ***\n";
    cout << "1 Show Queue\n";
    cout << "2 Insert new element\n";
    cout << "3 Remove element\n";
    cout << "4 Check the first element\n";
    cout << "5 to exit\n";
    cin >> input;
    return input;
}




int Menu::queueMenu() const {
    bool fl = true;
    int size, val;
    bool sub_flag;
    cout << "Enter the size of the queue:\n";
    cin >> size;
    myQueue* qu = new myQueue(size);
    int input = showqueueMenu();
    if (input == 5) { fl = 0; }
    while (fl) {
        switch (input) {
        case 1:
            cout << *qu;
            break;
        case 2:
            cout << "insert new element:" << endl;
            cin >> val;
            sub_flag = qu->enQueue(val);
            if (sub_flag) {
                cout << "The new queue:" << endl;
                //qu->print();
                cout << *qu;
            }
            else { cout << "Queue is full" << endl; }
            break;
        case 3:
            sub_flag = qu->deQueue();
            if (sub_flag) {
                cout << "The new queue:" << endl;

            }
            cout << *qu;
            break;
        case 4:
            if (!qu->isEmpty()) {
                cout << qu->peek() << endl;
            }
            else { cout << *qu; }
            break;
        case 5:
            fl = 0;
            break;
        default:
            cout << ERROR;
        }
        if (fl) { input = showqueueMenu(); }

    }
    return 0;
}
