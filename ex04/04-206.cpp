/*
 * leetcode 206 
 * reverse linked list
 *
 * double-pointer
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

// double pointer
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head, *pre = nullptr;
        while(cur != nullptr) {
            ListNode* tmp = cur->next; // store cur->next
            cur->next = pre;           // change cur->next
            // for the next loop
            pre = cur;                 
            cur = tmp;
        }
        return pre;
    }
};

// recursion
class Solution {
public:
    ListNode* reverse(ListNode* cur, ListNode* pre) {
        if (cur == nullptr) return pre;
        ListNode* res = reverse(cur->next, cur);
        cur->next = pre;
        return pre;
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(head, nullptr); // cur, prev
    }
};

