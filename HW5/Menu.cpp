/* Assignment C++: 3
   Author: Yuval Hendler
   Author: Ori Sadek
*/

#include <iostream>
#include "Menu.h"
#include "LinkedList.h"
#include "Shape.h"
#include "Square.h"
#include "Circle.h"
#include "OrthogonalTriangle.h"
#define SQUARE "square"
#define SIDE_L "side length"
#define CIRCLE "circle"
#define CIRCLE_R "radius"
#define TRIANGLE "triangle"
#define TRY_AGAIN "please try again\n";
#define INVALID_CHOICE "Invalid choice\n"
#define INVALID_SELECTION "Invalid selection.\n"
using namespace std;
Menu::Menu(){} //constructor

Menu::~Menu(){} // destructor

int  Menu::getInput()const { // get the answer to menu
	int input;
    cout << "======================================="<<endl;
	cout << "<1>Add element to the list"<<endl;
	cout << "<2>Remove the last shape from list" << endl;
	cout << "<3>Print the last shape" << endl;
	cout << "<4>Exit" << endl;
    cout << "=======================================" << endl;
	cin >> input;
	return input;
}

double Menu::getLengthAndColor(char* obj_color,const char* shape,const char* length)const{ //get the color from user
    int obj_len;
        cout << "Enter "<< shape<<"'s color:"<<endl;
        cin >> obj_color;
        cout << "Enter " << shape << "'s "<<length<<endl;
        cin >> obj_len;
return obj_len;
}


void printShape(Shape* s) { // print shape
    cout << s->getName() << " details: ";
    cout <<"color="<< s->get_color();
    bool draw = false;
    const char* len_prop;
    if (typeid(*s) == typeid(Circle)) { // use RTTI
        len_prop = CIRCLE_R;
        draw = false;
    }else {
        draw = true;
        len_prop = SIDE_L;
    }
    
    cout << ", "<<len_prop << "=" << s->getLengthProp() << endl;
    cout << "area=" << s->getArea() << ", "<< "perimeter=" << s->getPerimeter()<<endl;
    if (draw) {
        try {
            OrthogonalTriangle* temp = dynamic_cast<OrthogonalTriangle*>(s); // use RTTI
            if (temp == nullptr)throw "Not a Triangle";
            temp->draw();
        }
        catch (...) {
            try {
                Square* temp = dynamic_cast<Square*>(s);
                if (temp == nullptr)throw "s Not an Shape";
                temp->draw();
            }
            catch (char* msg) { 
                cout << msg;
            }   
        }
    }
   
}
Shape* getShape(const Menu* m,const int obj_type,bool& getType) { //create the shape
            double obj_len;
            char obj_color[6]="\0"; // initialize color name
            switch (obj_type) {
            case 1:
                obj_len = m->getLengthAndColor(obj_color, SQUARE, SIDE_L); // get the color due to the shape
                getType = true; // state that an shape was chosen
                return new Square(obj_color, obj_len); // return pointer to Square (that is type of Shape)
                break;
            case 2:
                obj_len = m->getLengthAndColor(obj_color, CIRCLE, CIRCLE_R);// get the color due to the shape
                getType = true; // state that an shape was chosen
                return new Circle(obj_color, obj_len); // return pointer to Circle (that is type of Shape)
                break;
            case 3:
                obj_len = m->getLengthAndColor(obj_color, TRIANGLE, SIDE_L);// get the color due to the shape
                getType = true;// state that an shape was chosen
                return new OrthogonalTriangle(obj_color, obj_len); // return pointer to OrthogonalTriangle (that is type of Shape)
                break;
            default:
                throw INVALID_CHOICE; // throw error
                break;
            }
}


int Menu::mainMenu() const{
	int fl = 1,fl1=1;
    int obj_type;
    bool getType = false;
    
    LinkedList<Shape*> L;
	while (fl) {
		int input = getInput();
        getType = false;
        obj_type = 0;
        switch (input) {
        case 1:
            cout << endl;
            fl1 = 1;
                while (fl1) {
                    try {
                        if (!getType) { // if not right shape was chosen 
                            cout << "Choose 1 for Square, 2 for Circle, 3 for Triangle: ";
                            cin >> obj_type;
                        }
                        L.insert(getShape(this, obj_type, getType)); // insert shape to list
                        fl1 = 0;
                    }
                    catch (const char* msg) {
                        cout << msg;
                        cout << TRY_AGAIN;

                    }
                    catch (invalid_argument) {
                        cout << TRY_AGAIN;
                    }
                }
            break;
        case 2:
            cout << endl;
            try {
                delete L.deleteNode(); // delete the last shape that inserted
            }
            catch (const char* msg) {
                cout << msg;
                cout << TRY_AGAIN;
            }
            break;
        case 3:
            cout << endl;
            try {
                printShape(L.getTop()); // print the last shape that inserted
                cout << endl;
            }
            catch (const char* msg) {
                cout << msg;
            }
     
            break;
        case 4:
            fl = 0;
            try {
                while (1) {
                    delete L.deleteNode(); //free all the shapes in List
                }
            }
            catch(...){
                cout << "Goodbye!";
            }
            break;
        default:
            cout << INVALID_SELECTION;
        }
	}
    return 0;
}
