/* Assignment C++: 3
   Author: Yuval Hendler
   Author: Ori Sadek
*/

#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H
#include "Node.h"
#define ERROR_EMPTY "Exception: The List is empty!\n"
using namespace std;

template<class T> class LinkedList {
private:
	Node<T>* head;
public:
	LinkedList() {
		head = nullptr; //constructor
	}
	~LinkedList() { // destructor
		Node<T>* temp = head;
		while (temp != nullptr) { //release memory
			Node<T>* tempNext = temp->getNext();
			delete temp;
			temp = tempNext;
		}
	}
	void insert(const T& data) { 
		Node<T>* n =  new Node<T>(data); //dynamic allocation
		if (head != nullptr) { // head to be the next
			n->setNext(head);
		}
		head = n; // head is the current node
	}
	T deleteNode(){
		T val;
		if (head == nullptr)throw ERROR_EMPTY; // if the list is empty
		val = head->getData(); // get the value
		Node<T>* headNext =head->getNext();
		delete head; // release memory
		head = headNext;
		return val;
	}

	T deleteNode(const T& data) {
		Node<T>* prev = nullptr; // define defult pointer
		Node<T>* curr = searchNode(data, prev); // search the node
		if (curr == nullptr) throw ERROR_EMPTY;
		if (curr == head)return this->deleteNode(); //delete the head
		prev->setNext(curr->getNext()); // change the next
		T retData = curr->getData();
		delete curr;
		return retData;
	}
	bool search(const T& data) const{
		Node<T>* ans = searchNode(data);
		if (ans == nullptr) return false; 
		else return true; 
	}

	Node<T>* searchNode(const T& data,Node<T>* p = nullptr)const { // search function
		Node<T>* ans = nullptr;
		int fl = 1;
		if (head == nullptr) return ans;
		Node<T>* temp = head;
		Node<T>* prev = nullptr;
		while (temp!=nullptr&&fl) {
			if (temp->getData() == data) {
				ans = temp;
				p = prev;
				fl = 0;
			}else {
				prev = temp;
				temp = temp->getNext();
			}	
			}
		return ans;
	}

	const T& getTop() const {
		if(head == nullptr)throw ERROR_EMPTY;
		return head->getData();
	}

	friend ostream& operator<<(ostream& os, const LinkedList& L ) { //print the list
		if (L.head == nullptr)throw ERROR_EMPTY;
			Node<T>* temp = L.head;
			while (temp!= nullptr) {
				os << temp->getData() <<endl;
				temp = temp->getNext();
			}
		
		return os;
	}

};

#endif