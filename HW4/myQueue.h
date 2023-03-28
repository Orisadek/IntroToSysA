/* Assignment C++: 2
   Author: Yuval Hendler
   Author: Ori Sadek
*/

#ifndef WH4_MYQUEUE_H
#define WH4_MYQUEUE_H
#include <vector>
#include <ostream>

using namespace std;

class myQueue {
    std::vector<int> qu;
    int maxQ;
public:
    //friend ostream& operator<<(ostream& os, const myQueue& q);
    myQueue(int maxQ);
    bool enQueue(int val);
    bool deQueue();
    bool isEmpty() const;
    int peek();
    friend ostream& operator<<(ostream& os, const myQueue &q);
    ~myQueue();


};
#endif //WH4_MYQUEUE_H
