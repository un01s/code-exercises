/*
 * leetcode 876
 * middle of the linked list
 *
 * Given the head of a singly linked list, return the middle node of the 
 * linked list.
 * 
 * If there are two middle nodes, return the second middle node.
 *
 * input: head = [1, 2, 3, 4, 5]
 * return: [3, 4, 5]
 *
 * input: head = [1, 2, 3, 4, 5, 6]
 * return: [4, 5, 6]
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
// slow and fast pointer:
// slow moves one step, fast moves two steps at the same time
// so when the fast reaches the end, slow is at the middle.
//
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

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
