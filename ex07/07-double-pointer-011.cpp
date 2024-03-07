/*
 * leetcode 142
 * linked list cycle II
 * 
 * fast-slow pointer
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
    ListNode *detectCycle(ListNode *head) 
    {
        if (head==nullptr) return nullptr;
        
        ListNode* slow=head;
        ListNode* fast=head;
        int flag=0;
        
        while (fast->next!=nullptr && fast->next->next!=nullptr) {
            fast=fast->next->next;
            slow=slow->next;
            
            if (fast==slow) {
                flag=1;
                break;
            }
        }
        
        if (flag==0) return nullptr;
        
        fast=head;
        while (fast!=slow) {
            fast=fast->next;
            slow=slow->next;
        }
        
        return fast;
        
    }
};

