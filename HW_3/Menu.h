/* Assignment C++: 1
   Author: Yuval Hendler
   Author: Ori Sadek
*/


class Menu {
	int showJuiceMenu() const; //take the input of the choosen juice
	int showStackMenu() const;
public:
	~Menu(); //Destructor
	Menu(); //Constructor
	int mainMenu() const; //regular menu
	int shopMenu() const; //shop menu
	int stackMenu() const;  //stack menu
};