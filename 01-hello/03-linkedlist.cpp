/*
 * linked list
 *
 * introduce a dummy head will make the operations on a linked list 
 * all the same to both head and non-head nodes.
 *  
 *
 */

#include <iostream>
#include <vector>
#include <string>

struct ListNode {
    int val;
    ListNode* next;
    // constructor
    ListNode(int x) : val(x), next(nullptr) {}
};

void insert(ListNode* n, ListNode* p) {
    // insert p right after n
    ListNode* tmp = n->next;
    p->next = tmp;
    n->next = p;
}

void remove(ListNode* head, ListNode* p) {
    
}

// find the first node index whose value is val
int find(ListNode* head, int val) {
    int index = 0;
    while (head != nullptr) {
        if (head->val == val) return index;
        head = head->next;
        index++;
    }
    return -1;
}

int main() {
    return 0;
}
