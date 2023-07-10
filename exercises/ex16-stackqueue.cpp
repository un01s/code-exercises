/*
 * use two stacks to implement a queue
 *
 * we have two stacks stIn, and stOut. Push into the stIn, pop from the stOut.
 * whenever pop, move the elements from stIn to stOut, stOut.push(stIn.pop()),
 * this reverse the order from FILO to FIFO.
 *
 */

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
    stack<int> stIn;
    stack<int> stOut;
public:
    MyQueue() {
    }

    void push(int x) {
        stIn.push(x);
    }

    int pop() {
        if(!stOut.empty()) {
            int res = stOut.top();
            stOut.pop();
            return res;
        } else {
            // copy from input stack
            while(!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
            int res = stOut.top();
            stOut.pop();
            return res;
        }
    }

    int peek() {
        if (stOut.empty()) {
            while(!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        return stOut.top();
    }

    bool empty() {
        return stOut.empty() and stIn.empty();;
    }
};

int main() {
    MyQueue* q = new MyQueue();
    q->push(1);
    q->push(2);
    q->push(3);
    cout << "top: " << q->peek() << endl;
    q->pop();
    cout << "top: " << q->peek() << endl;

    return 0;
}
