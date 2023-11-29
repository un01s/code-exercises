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

// recursive
//
class Solution {
public:
    ListNode* reverse(ListNode* pre,ListNode* cur){
        if(cur == NULL) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        // the recursive actually dose the following two steps
        // pre = cur;
        // cur = temp;
        return reverse(cur,temp);
    }
    ListNode* reverseList(ListNode* head) {
        // initialization
        // ListNode* cur = head;
        // ListNode* pre = NULL;
        return reverse(NULL, head);
    }
};
