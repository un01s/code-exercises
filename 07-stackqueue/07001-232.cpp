/**
 * Leetcode 232 
 * https://leetcode.com/problems/implement-queue-using-stacks/
 *
 * 2023-07-03
 *
 */

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;

    MyQueue() {
        
    }
    
    void push(int x) {
        stIn.push(x);        
    }
    
    int pop() {
        // only when stOut empty, get all data from stIn
        if (stOut.empty()) {
            // get all data from stIn
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
            int result = stOut.top();
            stOut.pop();

            return result;
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
        return stIn.empty() && stOut.empty();
    }
};

int main() {
    MyQueue* q = new MyQueue();

    q->push(1);
    q->push(2);
    if (1 == q->peek()) {
        cout << "peek() gets 1" << endl; 
    } else {
        cout << "failed" << endl;
    }

    if (1 == q->pop()) {
        cout << "pop() gets 1" << endl;   
    } else {
        cout << "pop() failed" << endl;
    } 
    // 1, queue = [2]
    
    if (false == q->empty()) {
        cout << "queue is not empty" << endl;
    } else {
        cout << "empty() failed" << endl;
    }

    return 0;
}

