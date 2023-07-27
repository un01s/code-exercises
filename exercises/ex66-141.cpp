/*
 * leetcode 141
 *
 * fast-slow double-pointer
 *
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// brute force
class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> nodeSeen;
        while(head != nullptr) {
            if (nodeSeen.count(head)) {
                return true;
            } else {
                nodeSeen.insert(head);
            }
            head = head->next;
        }
        return false;
    }
};

// fast-slow double-pointer
class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if(slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    return 0;
}
