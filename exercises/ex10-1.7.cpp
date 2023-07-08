/*
 * implement a queue with two stacks
 * Leetcode 232 implement queue using stacks
 *
 * Implement a first in first out (FIFO) queue using only two stacks. 
 * The implemented queue should support all the functions of a normal queue 
 * (push, peek, pop, and empty).
 * 
 */

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> inSt, outSt;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        inSt.push(x);        
    }
    
    int pop() {
        if(outSt.empty()) {
            while(!inSt.empty()) {
                outSt.push(inSt.top());
                inSt.pop();
            }
        }
        int val = outSt.top();
        outSt.pop();
        return val;
    }
    
    int peek() {
        if (outSt.empty()) {
            while(!inSt.empty()) {
                outSt.push(inSt.top());
                inSt.pop();
            }
        }
        return outSt.top();
    }
    
    bool empty() {
        return inSt.empty() && outSt.empty();
    }
};

int main() {
    MyQueue* q = new MyQueue();

    q->push(1);
    q->push(2);
    q->push(3);
    if (q->empty()) {
        cout << "queue is empty" << endl;
    } else {
        cout << "queue is NOT empty" << endl;
    }

    q->pop();

    cout << "peek: " << q->peek() << endl;

    return 0;
}
