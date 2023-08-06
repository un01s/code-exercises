/**
 * 19 remove nth node from end of list
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *
 * Given the head of a linked list, remove the nth node from the end of 
 * the list and return its head.
 * 
 * How to solve this problem?
 *
 * For the singly linked list, use the dummyhead list. The reason is simple.
 * You do not need to deal with the head node and other nodes differently.
 * 
 * Use the double pointers here.
 * To remove the Nth node from the end of the list,
 * move the fast pointer N steps
 * then move both the fast and the slow pointers simulaneously until 
 * the fast pointer reach the tail of the list.
 * After this the slow pointer is pointing at the Nth from the end.
 *
 * this double-pointer approach is effecient in speed.
 * Before this, when solving the problem of 1721, the approach is clumsy.
 * find n the size of the list, then move n-k+1 forward to get the Kth from end.
 * It is slower than the double-pointer approach.
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
    pl->addAtTail(5);
    pl->show(); // 1, 2, 3, 4, 5
    pl->removeNthFromEnd(2);
    pl->show(); // 1, 2, 3, 5

    return 0;
}
