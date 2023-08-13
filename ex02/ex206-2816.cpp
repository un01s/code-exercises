/*
 * leetcode 2816
 * double a number represented as a linked list
 *
 * https://www.youtube.com/@techcourses4u
 * Tech Courses
 * 
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// recursive
// from the tail to start
class Solution {
public:
    int multiply(ListNode* cur) {
        // base condition
        if (cur == nullptr) return 0; // no carry
        
        int value = 2 * cur->val + multiply(cur->next);
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

// iterative
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        // reverse list
        head == reverseList(head);
        // iterate list
        int carry = 0;
        ListNode* ptr = head;
        while(ptr) {
            // multiply by 2 and add carry
            int value = ptr->val * 2 + carry;
            ptr->val = value%10;
            carry = value/10;
            if ((ptr->next == nullptr) && carry) {
                ptr->next = new ListNode(carry);
                ptr = ptr->next;
            }
            ptr = ptr->next;
        }
        return reverseList(head);
    }
};

