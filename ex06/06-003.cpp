/*
 * leetcode 21
 * merge two sorted lists
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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;

        while(list1!=nullptr && list2!=nullptr) {
            if(list1->val <= list2->val) {
                cur->next = list1;
                list1 = list1->next;
            }else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        while(list1) {
            cur->next = list1;
            list1 = list1->next;
            cur = cur->next;
        }

        while(list2) {
            cur->next = list2;
            list2 = list2->next;
            cur = cur->next;
        }

        return dummy->next;        
    }
};

