/*
 * leetcode 2816
 * double a number represented as a linked list
 * 
 */

// recursion
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// from the tail to start
class Solution {
public:
    int multiply(ListNode* cur) {
        // base condition
        if (cur == nullptr) return 0; // no carry
        
        int value = 2 * cur->val + multiply(cur->mext);
        cur->val = value%10;

        return value/10; // carry        
    }
    ListNode* doubleIt(ListNode* head) {
        int carry = multiply(head);
        if (carry) {
            head = new ListNode(carry, head);
        }
        return head;        
    }
};

