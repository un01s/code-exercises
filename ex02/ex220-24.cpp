/*
 * leetcode 24
 * swap nodes in pairs
 * 
 * linked list
 *
 */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* h = head;
        ListNode* temp = h->next->next;
        head = h->next;
        h->next->next = h;
        h->next = temp;

        while(h->next && h->next->next) {
            ListNode* temp = h->next->next->next;
            ListNode* t = h->next->next;
            h->next->next->next = h->next;
            h->next->next = temp;
            h->next = t;    
            h = h->next->next;
        }
        return head;
    }
};

