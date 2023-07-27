/*
 * leetcode 143 reorder list
 *
 * fast-slow double-pointer
 *
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// brute force
class Solution {
public:
    void reorderList(ListNode* head) {
        // corner case
        if (!head || !head->next) return;

        // sort all nodes into a vector
        vector<ListNode*> v;

        while(head != nullptr) {
            v.push_back(head);
            head = head->next;
        }

        // reassign the next pointer
        int i = 0, j = v.size()-1;
        while(i+1 < j) {
            v[i]->next = v[j];
            v[j]->next = v[i+1];
            ++i;
            --j;
        }
        v[j]->next = nullptr;
        return;
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
