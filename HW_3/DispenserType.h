/* Assignment C++: 1
   Author: Yuval Hendler
   Author: Ori Sadek
*/

class DispenserType {
	int numberOfItems;
	int cost;
public:
	DispenserType(); //Constructor
	DispenserType(int numberOfItems, int cost); //Constructor
	~DispenserType(); //Destructor
	int getNoOfItems() const;
	int getCost() const;
	void makeSale();

};