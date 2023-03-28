/* Assignment C++: 1
   Author: Yuval Hendler
   Author: Ori Sadek
*/


class StackNode {
	int data;
	StackNode* next;
public:
	StackNode(int num = 0); //personal and default cons
	~StackNode(); //default dest
	int get_data() const;
	void set_next(StackNode* next);
	StackNode* get_next() const;

};