/*
 * leetcode 141
 * double-pointer: fast and slow
 * if both fast and slow pointers meet, there is a ring
 * checkout leetcode 142, to find out the entry point of the ring
 *
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

