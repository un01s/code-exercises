/*
 * leetcode 876
 *
 * slow-fast two-pointer
 *
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// slow-fast two-pointer
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int s = 0;
        ListNode* tmp = head;
        while(tmp->next) {
            s++;
            tmp = tmp->next;
        }
        int m = (s+1)/2;
        //cout << m << endl;
        for (int i = 0; i < m; i++) {
            head = head->next;
        }
        return head;
    }
};

// faster
class Solution2 {
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

int main() {
    return 0;
}
