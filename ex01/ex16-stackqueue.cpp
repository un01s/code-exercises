/*
 * use two stacks to implement a queue
 * leetcode 232
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
        if (stOut.empty()) {
            while(!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        } else {
            stack<int> tmp;
            while(!stOut.empty()) {
                tmp.push(stOut.top());
                stOut.pop();
            }
            while(!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
            while(!tmp.empty()) {
                stOut.push(tmp.top());
                tmp.pop();
            }
        }
        if(!stOut.empty()) {
            int res = stOut.top();
            stOut.pop();
            return res;
        } else {
            return NULL;
        }
    }

    int peek() {
        if(stOut.empty()) {
            while(!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        } else {
            stack<int> tmp;
            while(!stOut.empty()) {
                tmp.push(stOut.top());
                stOut.pop();
            }
            while(!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
            while(!tmp.empty()) {
                stOut.push(tmp.top());
                tmp.pop();
            }
        }
        if (!stOut.empty()) {
            int res = stOut.top();
            return res;
        } else {
            return NULL;
        }
    }

    bool empty() {
        return stOut.empty() and stIn.empty();;
    }
};

int main() {
    MyQueue* q = new MyQueue();
    q->push(1);
    q->push(2);
    cout << "top: " << q->peek() << endl;
    cout << "pop: " << q->pop() << endl;
    if (q->empty()) {
        cout << "q is empty" << endl;
    } else {
        cout << "q is NOT empty" << endl;
    }
    return 0;
}
