/*
 * leetcode 19
 * delete the n-th node from the end
 *
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        while(n-- && fast != NULL) {
            fast = fast->next;
        }
        // move the fast pointer one node more
        // so that the slow is going to point to the node just before
        // the one to be deleted
        fast = fast->next;
        // now fast is at n+1

        // both fast and slow moves together until 
        // the fast reaches the end
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next; 
        
        // ListNode *tmp = slow->next;  // release the memory
        // slow->next = tmp->next;
        // delete nth;
        
        return dummyHead->next;
    }
};
