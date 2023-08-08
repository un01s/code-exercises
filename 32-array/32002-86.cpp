/*
 * leetcode 86
 * remove the duplicates from a sorted linked list
 *
 * Given the head of a sorted linked list, delete all duplicates such that 
 * each element appears only once. Return the linked list sorted as well.
 *
 *
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    // constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        // use double-pointer
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr) {
            if (fast->val != slow->val) {
                slow->next = fast;
                slow = slow->next;
            }
            fast = fast->next;
        }
        // break with the duplicates at the end
        slow->next = nullptr;
        return head;        
    }
};

int main() {
    Solution s;
    
    return 0;
}
