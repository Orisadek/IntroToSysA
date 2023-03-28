/* Assignment C++: 3
   Author: Yuval Hendler
   Author: Ori Sadek
*/
#ifndef __NODE_H
#define __NODE_H
template<class T> class Node {
private:
	T data;
	Node<T>* Next;
public:
	Node(T data) { //constructor
		this->data = data;
		Next = nullptr;
	}
	~Node(){} 

	Node<T>* getNext() const  { // get the next node
		return Next;
	}
	const T& getData() const { // get the data in node
		return data;
	}
	void setNext(Node<T>* Next)  { //set the next node
		this->Next = Next;
	}
};
#endif