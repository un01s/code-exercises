/**
 * Leetcode 225 use queue to implememt stack
 *
 *
 * 2023-07-04
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MyStack {
public:
    queue<int> que1;
    queue<int> que2; // backup
    /** Initialize your data structure here. */
    MyStack() {
    }

    /** Push element x onto stack. */
    void push(int x) {
        que1.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = que1.size();
        size--;
        while (size--) { // last one of que1
            que2.push(que1.front());
            que1.pop();
        }

        int result = que1.front(); // 
        que1.pop();
        que1 = que2;        
        while (!que2.empty()) { // empty que2
            que2.pop();
        }
        return result;
    }

    /** Get the top element. */
    int top() {
        return que1.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que1.empty();
    }
};

int main() {
    
    return 0;
}

