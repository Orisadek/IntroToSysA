/* Assignment C++: 1
   Author: Yuval Hendler
   Author: Ori Sadek
*/


class CashRegister {
	int cashOnHands;
public:
	~CashRegister(); // Destructor
	CashRegister(int cashNum = 0); // Constructor
	int getCurrentBalance() const;
	void acceptAmount(int payedMoney);
};