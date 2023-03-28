/* Assignment C++: 2
   Author: Yuval Hendler
   Author: Ori Sadek
*/
#include "Set.h"
#include <iostream>
using namespace std;

Set::Set(int maxSize) {
	currentSize = 0;;
	this->arr = new int[maxSize];
	this->maxSize = maxSize;
}

Set::Set(const Set& set) {
	*this = set; // use of the = operator
}

int* Set::getNewArray(const int* arr,const int len)const {
	int* arr_tmp = new int[len]; // create new arr in length len
	for (int i = 0; i < currentSize; i++) {
		*(arr_tmp + i) = arr[i]; //copy the values
	}
	return arr_tmp; //return the arr
}

void Set::setNewArrLength(int len) { 
	int* arr_tmp = getNewArray(arr,len); // copy arr (deap copy) 
	delete[] arr; // delete the old arr
	arr = arr_tmp; // copy the new adress
}

int Set::getCurrentSize()const {
	return currentSize;
}

int Set::NumberInSet(const int num,const Set& set ) const {
	//find if number already in set
	int fl = 1, counter = 0, fl_tmp = 0;
	while (fl) {
		if (set.arr[counter] == num)fl = 0;
		else if (counter >= set.currentSize - 1)fl_tmp = 1, fl = 0;
		counter++;
	}
	return fl_tmp;
}

void Set::setCurrentVal(Set& set, const int num)const {
	int fl_tmp = NumberInSet(num, set); // find if val in set
	if (fl_tmp) {
		set.currentSize++; // increase the current Size
		if (set.currentSize > set.maxSize)set.setNewArrLength(2 * set.maxSize), set.maxSize = 2 * maxSize; //increase the set and maxsize
		set.arr[set.currentSize - 1] = num;//put the new val in set
	}
}

const Set Set::operator + (const int num) const {
	Set set1;//create new set 
	set1.currentSize= currentSize; // copy current Size to the new set
	delete[] set1.arr; // delete the old arr
	set1.arr = set1.getNewArray(arr, maxSize);// copy arr (deap copy)
	setCurrentVal(set1, num); //add new val to set
	return set1;
}


const Set Set::operator + (const Set& set) const {
	int maxL = maxSize;
	if (currentSize + set.currentSize > maxSize) maxL = currentSize + set.currentSize; // so we won't need to allocate new memory
	Set set1(maxL);//create new set in length maxL
	set1.currentSize= currentSize; 
	delete[] set1.arr;
	set1.arr = set1.getNewArray(arr, maxL); // copy arr (deap copy) in length maxL
	for (int i = 0; i < set.currentSize; i++) {
		setCurrentVal(set1, set.arr[i]); // insert all the val in set to set1
	}
	return set1;
}

const Set operator+(int num, const Set& set) { //friend function
	Set set1(set);
	set.setCurrentVal(set1, num); // insert the val to set
	return set1;
}


bool Set::operator>(const Set& set)const {
	if (currentSize > set.currentSize)return true;
	else return false;
}


void Set::operator += (const int num) {
	int fl_tmp = NumberInSet(num,*this); // find if val in set
	if (fl_tmp) {
		currentSize++;
		if (currentSize > maxSize)setNewArrLength(2* maxSize),maxSize= 2 * maxSize; //increase memory
		arr[currentSize - 1] = num;
	}
}

const Set& Set::operator = (const Set& set) {
	if (&set != this) { // if not equal to itself
		maxSize = set.maxSize; 
		currentSize = set.currentSize; 
		delete[] arr;
		arr = getNewArray(set.arr, maxSize); // copy arr (deap copy)
	}
	return *this;
}

const int& Set::operator [] (const int i)const {
	return arr[i];
}

Set::~Set() {
	delete[] arr; // destructor
}

ostream& operator<<(ostream& os, const Set& set) {
	os << "{";
	for (int i = 0; i < set.getCurrentSize(); i++) { // go through the values in set
		os << set[i]; // print set[i]
		if (i != set.getCurrentSize() - 1) {
			os << ",";
		}
	}
	os << "}"<<endl;
	return os;
}


