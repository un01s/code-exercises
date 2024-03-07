/*
 * leetcode 141
 * linked list cycle
 *
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        if (head==nullptr) return false;
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while (fast->next!=nullptr && fast->next->next!=nullptr)
        {
            fast=fast->next->next;
            slow=slow->next;
            
            if (fast==slow) return true;
        }
        
        return false;
        
    }
};
