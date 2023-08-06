/*
 * leetcode 86
 *
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

//
class Solution {
public:
    ListNode* partition(ListNode* head, int k) {
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);

        ListNode* p1 = dummy1, p2 = dummy2;
        ListNode* p = head;

        while(p != nullptr) {
            if(p->val >= k) {
                p2->next = p;
                p2 = p2->next;
            } else {
                p1->next = p;
                p1 = p1->next;
            }
            // break the original link
            ListNode* tmp = p->next;
            p->next = nullptr;
            p = tmp;                    
        }

        // connect two lists
        p1->next = dummy2->next;

        return dummy1->next;
    }
};
