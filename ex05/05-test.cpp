/*
 *
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        // length of list A
        while (curA != nullptr) {
            lenA++;
            curA = curA->next;
        }
        // length of list B
        while (curB != nullptr) {
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        // curA for longer one
        if (lenB > lenA) {
            swap (lenA, lenB);
            swap (curA, curB);
        }
        // find out the difference
        int gap = lenA - lenB;
        // tail aligned
        while (gap--) {
            curA = curA->next;
        }
        // traverse both
        while (curA != nullptr) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};
