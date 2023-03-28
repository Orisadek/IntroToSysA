/* Assignment C++: 2
   Author: Yuval Hendler
   Author: Ori Sadek
*/

#include "myQueue.h"
#include "iostream"
using namespace  std;


myQueue::myQueue(int maxQ) {
    this->maxQ = maxQ;
}

bool myQueue::isEmpty() const{
    if(qu.size() == 0){
        return true;
    }
    return false;
}
bool myQueue::enQueue(int val) {
    if (qu.size() != maxQ){
        qu.push_back(val);
        return true;
    }
    return false;
}

bool myQueue::deQueue() {
    if (!isEmpty()){
        qu.erase(qu.begin());
        return true;
    }
    return false;
}

int myQueue::peek() {
    if (isEmpty()){
        return -1;
    }
    return qu.front();
}

ostream& operator<<(ostream& os, const myQueue &q) {
    if(q.isEmpty()){
        os<<"Queue is empty"<<endl;
        return os;
    }
    for(int i=0; i < q.qu.size(); i++){
        if(i==q.qu.size()-1){
            os << q.qu.at(i)<< endl ;
        } else{os << q.qu.at(i) << "<-";}
    }

    return os;
}



myQueue::~myQueue() {
    qu.clear();
    qu.shrink_to_fit();

}



