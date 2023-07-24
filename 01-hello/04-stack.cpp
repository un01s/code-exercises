/*
 * stack 
 * 
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// use linked list to implement stack
// use the head of a linked list as the top of the stack
struct ListNode {
    int val;
    ListNode* next;
    // constructor
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedListStack {
private:
    ListNode* stackTop; // head node as the stack top
    int stackSize; 
    
public:
    LinkedListStack() {
        stackTop = nullptr;
        stackSize = 0;
    }
    ~LinkedListStack() {
        freeMemoryLinkedList(stackTop);
    }
    void freeMemoryLinkedList(ListNode* head) {
        while (head->next != nullptr) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
            stackSize--;
        }
        delete head;
        stackSize--;
    }
    int size() {
        return stackSize;
    }
    bool empty() {
        return size() == 0;
    }
    void push(int val) {
        ListNode* node = new ListNode(val);
        node->next = stackTop;
        stackTop = node;
        stackSize++;
    }
    void pop() {
        int val = top();
        ListNode* tmp = stackTop;
        stackTop = stackTop->next;
        delete tmp;
        stackSize--;
    }
    int top() {
        if (size() == 0) {
            throw out_of_range("out of range");
        }
        return stackTop->val;
    }
};


// use array to implement stack
// use the tail of array as the top of the stack
class ArrayStack {
private:
    vector<int> st;
public:
    int size() {
        return st.size();
    }
    bool empty() {
        return st.empty();
    }
    void push(int val) {
        st.push_back(val);
    }
    void pop() {
        int oldTop = top();
        st.pop_bacK();
    }
    int top() {
        if (empty()) {
            throw out_of_range("out of range");
        }
        return st.back();
    }
};


int main() {
    // basic stack operations
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "stack size = " << st.size() << endl;
    int top = st.top();
    cout << "stack top = " << top << " \n";
    st.pop();
    cout << "stack pop" << endl;
    cout << "stack size = " << st.size() << endl;
    cout << "stack top = " << st.top() << endl;
    if (st.empty()) {
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is NOT empty" << endl;
    }
    
    return 0;
}
