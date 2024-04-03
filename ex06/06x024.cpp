/*
 * leetcode 24
 * swap nodes in pairs in a linked list
 *
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next;
            ListNode* tmp1 = cur->next->next->next;

            cur->next = cur->next->next;  // 1
            cur->next->next = tmp;        // 2
            cur->next->next->next = tmp1; // 3

            cur = cur->next->next; // move forward for next swap
        }
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};

