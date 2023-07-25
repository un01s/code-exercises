/*
 * queue
 *
 * deque can be implemented by doubly-linked-list or array
 *
 */

#include <iostream>
#include <queue>
#include <deque> // bidirectional queue

using namespace std;

struct ListNode {
    int val;		// node value
    ListNode *next;	// next node
    // constructor
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedListQueue {
private:
    ListNode* front;
    ListNode* rear;
    int qSize;
public:
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
        qSize = 0;
    }
    ~LinkedListQueue() {
        freeMemoryLinkedList(front);
    }
    void freeMemoryLinkedList(ListNode* front) {
        // TODO
        // need free all nodes one after another
    }
    int size() {
        return qSize;
    }
    bool empty() {
        return qSize == 0;
    }
    void push(int val) {
        ListNode* node = new ListNode(val);
        if (front == nullptr) {
            front = node;
            rear = node;
        } else {
            rear->next = node;
            rear = node;
        }
        qSize++;
    }
    void pop() {
        int num = peek();
        ListNode* tmp = front;
        front = front->next;
        delete tmp;
        qSize--;
    }
    int peek() {
        if (size() == 0) {
            throw out_of_range("out of range");
        }
        return front->val;
    }
};

class ArrayQueue {
private:
    int* nums;
    int front;
    int qSize;
    int qCapacity;
    
public:
    ArrayQueue(int cap) {
        nums = new int[cap];
        qCapacity = cap;
        front = qSize = 0; // index
    }
    ~ArrayQueue() {
        delete[] nums;
    }
    int capacity() {
        return qCapacity;
    }
    int size() {
        return qSize;
    }
    bool empty() {
        return size() == 0;
    }
    void push(int val) {
        if (qSize == qCapacity) {
            cout << "queue is full" << endl;
            return;
        }
        int rear = (front + qSize) % qCapacity;
        nums[rear] = val;
        qSize++;
    } 
    void pop() {
        int val = peek();
        front = (front + 1)%qCapacity;
        qSize--;
    }
    int peek() {
        if (empty()) {
            throw out_of_range("out of range");
        }
        return nums[front];
    }
};

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "q front:" << q.front() << endl;
    cout << "q size:" << q.size() << endl;
    cout << "q pop" << endl;
    q.pop();
    cout << "q front:" << q.front() << endl;
    cout << "q size:" << q.size() << endl;

    // bi-directional queue
    deque<int> qq;
    qq.push_back(1);
    qq.push_back(2);
    qq.push_back(3);
    qq.push_front(11);
    qq.push_front(22);
    cout << "deque front:" << qq.front() << endl;
    cout << "deque back:" << qq.back() << endl;
    cout << "deque size:" << qq.size() << endl;
    
    return 0;
}
