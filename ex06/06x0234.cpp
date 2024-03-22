/*
 * leetcode 234
 * palindrome linked list
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
    bool isPalindrome(ListNode* head) {
        // Initialize pointers for slow, fast, prev, and next nodes
        ListNode *slow = head, *fast = head, *prev = nullptr, *next = head;

        // Move fast pointer to the end of the list
        while (fast->next != nullptr) {
            fast = fast->next; // Move fast pointer
            next = slow->next; // Store next node for reversing
            slow->next = prev; // Reverse the slow pointer's next node
            prev = slow;       // Update prev to current slow node
            slow = next;       // Move slow pointer
            fast = fast->next; // Move fast pointer again
            if (fast == NULL) {
                break;
            }
        }

        // If the list has odd number of nodes, move slow pointer one step ahead
        if (fast != NULL) {
            slow = slow->next;
        }

        // Compare reversed first half with the second half
        while (slow != NULL) {
            if (slow->val != prev->val) {
                return false; // Return false if values don't match
            }
            slow = slow->next; // Move slow pointer forward
            prev = prev->next; // Move prev pointer forward
        }

        return true; // Return true if palindrome
    }
};

