/*
 * leetcode 206
 * reverse the linked list
 *
 */

// double-pointer
//
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp; // temporary storage for next
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur) {
            temp = cur->next;  // store cur->next
            cur->next = pre; // reverse
            // update both pre and cur
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

