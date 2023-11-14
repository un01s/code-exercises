/*
 * leetcode 21
 * merge two sorted lists
 *
 * linked list, dummy head for new list
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
        ListNode* o = list1;
        ListNode* p = list2;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (o != nullptr && p != nullptr) {
            if (o->val < p->val) {
                cur->next = o;
                o = o->next;
            } else {
                cur->next = p;
                p = p->next;
            }
            cur = cur->next;
        }
        if (o != nullptr) cur->next = o;
        if (p != nullptr) cur->next = p;
        
        return dummy->next;
    }
};

/**
 * recursive
 * the key point is to have the terminating condition
 * or the code will crash in the end
 * 
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } 
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
};

