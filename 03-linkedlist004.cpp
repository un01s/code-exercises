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
    // 24 swap pairs
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
    // 1721 swapping nodes in a linked list
    // https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
    // d -> 1 -> 2 -> 3 -> 4 -> 5, k = 2
    // d -> 1 -> 4 -> 3 -> 2 -> 5
    // node 2 and node 4 is the target
    // we need node1 and node3 for swapping
    // pre1 = 1
    // first = 1->next
    // next1 = first->next
    // pre2 = 3
    // second = 3->next
    // next2 = second->next
    void swapNodes(int k) {
        // locate the first node 
        ListNode* before1 = _dummyHead;
        int index1 = k-1;
        while(index1--) {
            before1 = before1->next;
        }
        cout << "before1:" << before1->val;

        // locate the tail and then the second node
        ListNode* tail = _dummyHead;
        int length = 0;
        while(tail->next != nullptr) {
            tail = tail->next;
            length += 1;
        }
        cout << " length:" << length;
        int index2 = length-k;
        cout << " index2:" << index2;
        ListNode* before2 = _dummyHead;
        while(index2--) {
            before2 = before2->next;
        }
        cout << " before2:" << before2->val << endl;
        //
        if (before1->next != before2->next) {
            ListNode* first = before1->next;
            ListNode* second = before2->next;
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            before1->next = before2->next;
            second->next = tmp1;
            tmp1->next = first;
            first->next = tmp2;
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

    // test2
    MyLinkedList* l2 = new MyLinkedList();
    l2->addAtHead(1);
    l2->addAtTail(2);
    l2->addAtTail(3);
    l2->addAtTail(4);
    l2->addAtTail(5);
    l2->show();
    l2->swapNodes(2);
    l2->show();

    // test3
    MyLinkedList* l3 = new MyLinkedList();
    l3->addAtHead(7);
    l3->addAtTail(9);
    l3->addAtTail(6);
    l3->addAtTail(6);
    l3->addAtTail(7);
    l3->addAtTail(8);
    l3->addAtTail(3);
    l3->addAtTail(0);
    l3->addAtTail(9);
    l3->addAtTail(5);
    l3->show(); // 7 9 6 6 7 8 3 0 9 5
    l3->swapNodes(5);
    l3->show(); // 7 9 6 6 8 7 3 0 9 5
 
    return 0;
}
