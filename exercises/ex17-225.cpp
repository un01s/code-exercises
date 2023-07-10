/*
 * use two queues to implement stack
 */

#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        // queue push to back
        q.push(x);
        for(int i = 0; i < q.size()-1; i++) {
            q.push(q.front());
            q.pop();
        } 
    }
    
    int pop() {
        int res = q.front();
        q.pop();
        return res;
    }
    
    int top() {
        int res = q.front();
        return res;
    }
    
    bool empty() {
        return q.empty();    
    }
};

int main() {
    MyStack* pSt = new MyStack();

    pSt->push(1);
    pSt->push(2);
    cout << "top: " << pSt->top() << endl;
    cout << "pop: " << pSt->pop() << endl;
    if (pSt->empty()) {
        cout << "stack is empty." << endl;
    } else {
        cout << "stack is NOT empty." << endl;
    }

    return 0;
}
