/*
 * implement a deque with array
 * O(1)
 *
 */

#include <iostream>

using namespace std;

#define ARRAY_SIZE 100

class Deque {
    int arr[ARRAY_SIZE];
    int head;
    int tail;
    int size;
public:
    Deque(int size) {
        head = -1;
        tail = 0;
        this->size = size;
    }
    void insertHead(int key);
    void insertTail(int key);
    void deleteHead();
    void deleteTail();
    bool isFull();
    bool isEmpty();
    int getHead();
    int getTail();
};

bool Deque::isFull() {
    return ((head == 0 && tail == size-1) ||
            head == tail+1);
}

bool Deque::isEmpty() {
    return (head == -1);
}

void Deque::insertHead(int key) {
    if (isFull()) {
        cout << "E: overflow" << endl;
        return;
    }
    if (head == -1) {
        head = 0;
        tail = 0;
    } else if (head == 0) {
        head = size-1;
    } else {
        head = head-1;
    }
    arr[head] = key;
}

void Deque::insertTail(int key) {
    if (isFull()) {
        cout << "E: overflow" << endl;
        return;
    }
    if (head == -1) {
        head = 0;
        tail = 0;
    } else if (tail == size-1) {
        tail = 0;
    } else {
        tail = tail+1;
    }
    arr[tail] = key;
}

void Deque::deleteHead() {
    if (isEmpty()) {
        cout << "E: underflow" << endl;
        return;
    }
    if (head == tail) {
        head = -1;
        tail = -1;
    } else if (head == size-1) {
        head = 0;
    } else {
        head = head+1;
    }
    return;
}

void Deque::deleteTail() {
    if (isEmpty()) {
        cout << "E: underflow" << endl;
        return;
    }
    if (head == tail) {
        head = -1;
        tail = -1;
    } else if (tail == 0) {
        tail = size-1;
    } else {
        tail = tail-1;
    }
}

int Deque::getHead() {
    if (isEmpty()) {
        cout << "E: Underflow" << endl;
        return -1;
    }
    return arr[head];
}

int Deque::getTail() {
    if (isEmpty() || tail < 0) {
        cout << "E: Underflow" << endl;
        return -1;
    }
    return arr[tail];
}

int main() {
    Deque dq(5);
    
    cout << "InsertTail 1" << endl;
    dq.insertTail(1);
    dq.insertTail(2);
    cout << "Tail=" << dq.getTail() << endl;
    dq.deleteTail();
    dq.insertHead(3);
    cout << "head=" << dq.getHead() << endl;

    return 0;
}
