/*
 * implement a stack using two queues
 * 
 * Leetcode 225
 *
 * Implement a last-in-first-out (LIFO) stack using only two queues. 
 * The implemented stack should support all the functions of a normal stack 
 * (push, top, pop, and empty).
 *
 *
 */
#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int qSize = q.size();
        q.push(x);
        while(qSize--) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int r = top();
        q.pop();
        return r;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

class MyStack2 {
private:
    queue<int> q1, q2;

public:
    MyStack2() {
        
    }
    
    void push(int x) {
        q1.push(x);        
    }
    
    int pop() {
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int r = q1.front();
        q1.pop();
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return r;
    }
    
    int top() {
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int r = q1.front();
        q1.pop();
        q2.push(r);
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return r;
    }
    
    bool empty() {
        if (q1.size() == 0) {
            return true;
        }
        return false;
    }
};

int main() {
    //MyStack* st = new MyStack();
    MyStack2* st = new MyStack2();

    st->push(1);
    st->push(2);
    cout << "stack top : " << st->top() << endl;
    st->pop();

    if (st->empty()) {
        cout << "my stack is empty" << endl;
    } else {
        cout << "my stack is NOT empty" << endl;
    }

    return 0;
}
