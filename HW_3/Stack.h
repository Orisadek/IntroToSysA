/* Assignment C++: 1
   Author: Yuval Hendler
   Author: Ori Sadek
*/

#include "StackNode.h"

class Stack {
	StackNode* top;
public:
	void mannagePush();
	Stack(); //default cons
	~Stack(); //default dest
	void push(int num);
	void pop();
	bool isEmpty() const;
	int peek() const;

};