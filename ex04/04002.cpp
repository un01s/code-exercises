/*
 * leetcode 2
 *
 * linked list
 * add two lists into one
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int carry = 0; 
        while (l1 || l2 || carry) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum/10;
            cur->next = new ListNode(sum%10);
            // 
            cur = cur->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummy->next;
    }
};


// recursion
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // terminating condition
        if (l1 == nullptr) {
            if (l2) return l2;
            else return nullptr;
        }
        if (l2) l1->val += l2->val;
        if (l1->val >= 10) {
            // carry
            if (l1->next) l1->next->val++;
            else l1->next = new ListNode(1);
            l1->val -= 10;
        }
        if (l2) l1->next = addTwoNumbers(l1->next, l2->next);
        else l1->next = addTwoNumbers(l1->next, nullptr);

        return l1;
    }
};

class Solution {
public:
    ListNode* addTwo(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 and !l2) {
            if (carry) {
                return new ListNode(1);
            }
            return nullptr;
        }
        int x = l1? l1->val : 0;
        int y = l2? l2->val : 0;
        int sum = x+y+carry;
        ListNode* n = new ListNode(sum%10);
        l1 = l1? l1->next : nullptr;
        l2 = l2? l2->next : nullptr;
        n->next = addTwo(l1, l2, sum/10);
        return n;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwo(l1, l2, 0);
    }
};

