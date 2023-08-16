/*
 * leetcode 25
 * reverse nodes in K group
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (k==1) return head;
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* p = dummy;
        while (p)
        {
            ListNode* q = p;
            int count = 0;
            while (q->next && count < k)
            {
                q = q->next;
                count++;
            }
            if (count < k)
                return dummy->next;
            
            ListNode* cur = p->next;
            ListNode* nxt = cur->next;
            ListNode* future = nxt->next;
            ListNode* start = cur;
            
            for (int i=0; i<k-1; i++)
            {
                nxt->next = cur;
                cur = nxt;
                nxt = future;
                if (future) future = future->next;
            }
            p->next = cur;
            start->next = nxt;
            
            p = start;
        }
        
        return dummy->next;        
    }
};

