/*
 * leetcode 21
 * merge two ordered linked list (ascending)
 *
 * Q: when to use the dummy head? 
 * A: when there is a need to create a new linked list.
 *
 */

struct ListNode {
    int val;
    ListNode *next;

    // constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// double-pointer
// the trick is that both linked-lists may not have the same length
// also because of maintaining the order in the new list
//
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p1 = l1, p2 = l2;
        ListNode* p = dummy;

        while(p1 != nullptr && p2 != nullptr) {
            if(p1->val > p2->val) {
                p->next = p2;
                p2 = p2->next;
            } else {
                p->next = p1;
                p1 = p1->next;
            }
            p = p->next;                    
        }

        // remaining
        if (p1 != nullptr) p->next = p1;
        if (p2 != nullptr) p->next = p2;

        return dummpy->next;
    }
};
