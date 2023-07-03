/**
 * Leetcode 206 reverse linked list 
 * Given the head of a singly linked list, reverse the list, and return 
 * the reversed list.
 *
 *
 * 2023-07-03
 * same as 03-linkedlist003.cpp
 * as review to check if I could do it again
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
        ListNode* tmp; 
        ListNode* current = head;
        ListNode* previous = nullptr;

        while(current) {
            tmp = current->next; // keep
            current->next = previous; // reverse the direction of pointer
            previous = current;
            current = tmp;
        }
        return previous;
    }    
};

// just run with leetcode
int main() {
    
    return 0;
}

