/**
 * 24 Swap nodes in pairs
 * https://leetcode.com/problems/swap-nodes-in-pairs/
 *
 * input:  1 -> 2 -> 3 -> 4
 * output: 2 -> 1 -> 4 -> 3
 *
 * Use the dummyHead for the linked list
 * input: d -> 1 -> 2 -> 3 -> 4
 * step1: d -> 2, cur = 1, tmp = cur->next, d -> 2
 * step2: 2 -> 1
 * step3: 1 -> 3
 *        
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);;
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next; // node 1 
            ListNode* tmp2 = cur->next->next->next; // node 3

            cur->next = cur->next->next; // d -> 2
            cur->next->next = tmp; // 2 -> 1
            cur->next->next->next = tmp2; // 1 -> 3

            cur = cur->next->next; // move 2 nodes forward
        }
        return dummyHead->next;
    }
};

// borrow code from linkedlist002.cpp
class MyLinkedList {
public:
    MyLinkedList() {
        _dummyHead = new ListNode(0);
        _size = 0;    
    }
    
    int get(int index) {
        if (index > (_size -1) || index < 0) {
            return -1;
        }
        ListNode* cur = _dummyHead->next;
        while(index--) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    // index = 0, newNode becomes new head
    // index = size, newNode becomes new tail
    // index > size, null
    // index < 0; new head
    void addAtIndex(int index, int val) {
        if (index > _size) return;
        if (index < 0) index = 0;
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        while(index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= _size || index < 0) {
            return;
        }
        ListNode* cur = _dummyHead;
        while(index--) {
            cur = cur->next;
        }
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;

        tmp = nullptr;
        _size--;
    }

    void show() {
        ListNode* cur = _dummyHead;
        while(cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void swapPairs() {
        ListNode* cur = _dummyHead;
        // actual head of the linked list
        //ListNode* head = cur->next;
        while(cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next;
            ListNode* tmp2 = cur->next->next->next;

            // step 1: cur->2
            cur->next = cur->next->next;
            // step 2: 2->1
            cur->next->next = tmp;
            // step 3: 1->3
            cur->next->next->next = tmp2;

            cur = cur->next->next; // move two nodes forward for next loop
        }
    }

private:
    int _size;
    ListNode* _dummyHead;
};

int main() {
    MyLinkedList* pl = new MyLinkedList();

    // test1
    pl->addAtHead(1);
    pl->addAtTail(2);
    pl->addAtTail(3);
    pl->addAtTail(4);
    pl->show();
   
    pl->swapPairs();
    pl->show();
 
    return 0;
}
