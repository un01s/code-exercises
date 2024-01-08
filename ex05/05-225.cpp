/*
 * leetcode 225
 * use queue to implemet stack
 *
 */

class MyStack {
public:
    queue<int> que1;
    queue<int> que2; // backup queue
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
        while (size--) { // move que1 into que2
            que2.push(que1.front());
            que1.pop();
        }

        int result = que1.front(); // the last one should be returned
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
