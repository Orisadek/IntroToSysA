/* Assignment C++: 2
   Author: Yuval Hendler
   Author: Ori Sadek
*/

#ifndef __SET_H
#define __SET_H
#include <iostream>
using namespace std;

class Set {
	int maxSize;
	int currentSize;
	int* arr;
	//useful methods
	void setNewArrLength(int len);
	int NumberInSet(const int num, const Set& set) const;
	void setCurrentVal(Set& set, const int num)const;
	int* getNewArray(const int* arr, const int len)const;
public:
	Set(int maxSize = 1000);//constructor
	Set(const Set& set); // copy constructor
	~Set(); // destructor
	int getCurrentSize()const; // get the current size of set

	//all the opertaors
	void operator += (const int num);
	const Set& operator = (const Set& set);
	const Set operator + (const int num) const;
	const Set operator + (const Set& set) const;
	bool operator > (const Set& set)const;
	const int& operator [] (const int i)const;
	friend const Set operator+(int num, const Set& set); // friend function
	friend ostream& operator<<(ostream& os, const Set& set);
};
#endif // __SET_H