/**
 * Leetcode 160 intersection of two linked lists
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists/
 * 
 * 
 * 
 *
 *  
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// solution
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        // get the length of each list
        while(curA != nullptr) {
            lenA++;
            curA = curA->next;
        }
        while(curB != nullptr) {
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        if (lenB > lenA) {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        // keep A as the longest one
        int gap = lenA - lenB;
        while(gap--) {
            curA = curA->next;
        }
        // two lists are tail-aligned now
        while(curA != nullptr) {
            if (curA == curB) {
                return curA; // the pointer to the intersection node
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr; // no intersection
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

    void appendListAtTail(ListNode* list) {
        ListNode* cur = list;
        int i = 0;
        while (cur != nullptr) {
            cur = cur->next;
            i++;
        }
        cout << "length=" << i << endl;
        ListNode* pre = _dummyHead;
        int j = 0;
        while (pre->next != nullptr) {
            pre = pre->next;
            j++;
        }
        cout << "length=" << j << endl;
        
        pre->next = list;
        _size = _size+i;
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

    ListNode* getDummyHead() {
        return _dummyHead;
    }

    ListNode* getListHead() {
        return _dummyHead->next;
    }

    // 1721 swapping nodes in a linked list
    // https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
    // d -> 1 -> 2 -> 3 -> 4 -> 5, k = 2
    // d -> 1 -> 4 -> 3 -> 2 -> 5
    // 
    // We need swap node2 with node4. 
    // Remember what we have is a singly linked list.
    // So we find the nodes just before node2 and node4.
    //
    // pre1 = node1
    // first = node1->next (i.e. node2)
    // next1 = first->next
    //
    // pre2 = node3
    // second = node3->next (i.e. node4)
    // next2 = second->next
    //
    void swapNodes(int k) {
        // locate the node before the first 
        ListNode* pre1 = _dummyHead;
        int index1 = k-1;
        while(index1--) {
            pre1 = pre1->next;
        }

        // locate the tail and then the node before the second
        ListNode* tail = _dummyHead;
        int length = 0;
        while(tail->next != nullptr) {
            tail = tail->next;
            length += 1;
        }
        int index2 = length-k;
        ListNode* pre2 = _dummyHead;
        while(index2--) {
            pre2 = pre2->next;
        }
        //
        if (pre1->next != pre2->next) {
            ListNode* first = pre1->next;
            ListNode* second = pre2->next;
            ListNode* next1 = first->next;
            ListNode* next2 = second->next;

            pre1->next = pre2->next;
            second->next = next1;
            next1->next = first;
            first->next = next2;
        }
    }
    // 19 remove Nth from the end of the list
    // https://leetcode.com/problems/remove-nth-node-from-end-of-list/
    void removeNthFromEnd(int n) {
        ListNode* fast = _dummyHead;
        ListNode* slow = _dummyHead;
        while(n-- && fast != nullptr) {
            fast = fast->next;
        }
        // fast starting from _dummyHead
        // after the above loop, fast is at the (n)th from start
        fast = fast->next;
        while(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        //cout << " slow:" << slow->val;
        // slow is at (n+1)th from end
        ListNode* tmp = slow->next->next;
        slow->next = tmp;
    }

    // 160 intersection of two linked lists
    ListNode *getIntersectionNode(ListNode *headB) {
        ListNode* curA = _dummyHead->next;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        // get the length of each list
        while(curA != nullptr) {
            lenA++;
            curA = curA->next;
        }
        while(curB != nullptr) {
            lenB++;
            curB = curB->next;
        }
        curA = _dummyHead->next;
        curB = headB;
        if (lenB > lenA) {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        // keep A as the longest one
        int gap = lenA - lenB;
        while(gap--) {
            curA = curA->next;
        }
        // tail aligned
        // two lists are tail-aligned now
        while(curA != nullptr) {
            if (curA == curB) {
                return curA; // the pointer to the intersection node
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr; // no intersection
    }

private:
    int _size;
    ListNode* _dummyHead;
};

int main() {
    MyLinkedList* l1 = new MyLinkedList();
    MyLinkedList* l2 = new MyLinkedList();
    MyLinkedList* l3 = new MyLinkedList();

    l1->addAtHead(1);
    l1->addAtTail(2);
    l1->addAtTail(3);
    l1->show(); // 1, 2, 3
    
    l2->addAtHead(10);
    l2->addAtTail(20);
    l2->show(); // 10, 20

    l3->addAtHead(31);
    l3->addAtTail(32);
    l3->addAtTail(33);
    l3->show(); // 31, 32, 33

    l1->appendListAtTail(l3->getListHead());
    l2->appendListAtTail(l3->getListHead());
    // have a possible memory leak: the dummyHead of l3
    l1->show();
    l2->show();

    // check if there is any intersection
    ListNode* i = l1->getIntersectionNode(l2->getListHead());
    if (i != nullptr) {
        cout << "intersection node value = " << i->val << endl;
    } else {
        cout << "no intersection" << endl;
    }

    return 0;
}
