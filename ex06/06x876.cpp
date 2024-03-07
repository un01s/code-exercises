/*
 * leetcode 876 
 * middle of the linked list
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head->next;

        while(fast!=NULL) {
            slow = slow->next; // slow moves only one step.
            fast = fast->next;
            if(fast) fast = fast->next; // If not at finish line move ahead.
        }

        return slow;    
    }
};

