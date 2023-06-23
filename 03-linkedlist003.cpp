/**
 * 206 Reverse linked list
 * https://leetcode.com/problems/reverse-linked-list/
 *
 */

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
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur) {
            tmp = cur->next; // keep this for next iteration 
            cur->next = pre; // reverse
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

