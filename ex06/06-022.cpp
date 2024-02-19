/*
 * leetcode 876
 * middle of the linked list
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
    ListNode* middleNode(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head;
        while(f != nullptr && f->next != nullptr) {
            f = f->next->next;
            s = s->next;
        }    
        return s;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int s = 0;
        ListNode* slow = head;
        while(head->next) {
            s++;
            head = head->next;
            if (s%2 == 0) {
                slow = slow->next;
            }
        }
        if (s%2 == 0) {
            return slow;
        } else {
            return slow->next;
        }
    }
};

