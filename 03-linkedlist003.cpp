/**
 * 206 Reverse linked list
 * https://leetcode.com/problems/reverse-linked-list/
 *
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* tmp;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur) {
            tmp = cur->next; // keep this for next iteration 
            cur->next = pre; // reverse
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

// recursive: reverse from head to tail
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head);
    }

    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if (cur == nullptr) return pre;
        ListNode* tmp = cur->next;
        cur->next = pre;
        // the next dose two steps in one
        // pre = cur
        // cur = tmp 
        return reverse(cur, tmp);
    }
};

// recursive: reverse from tail to head
class Solution3 {
public:
    ListNode* reverseList(ListNode* head) {
        // corner cases
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        //
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};
