/**
 * 203 remove linked list elements
 * https://leetcode.com/problems/remove-linked-list-elements/
 *
 * examples:
 * input: head = [1, 2, 6, 3, 4, 5, 6], val = 6
 * output: [1, 2, 3, 4, 5]
 *
 */

#include <iostream>
#include <vector>

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
    ListNode* removeElements(ListNode* head, int val) {
        // note: use "while" instead of "if"
        // remove head node
        while (head != nullptr && head->val == val) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp; // remove it from the memory
        }
        // remove non-head node
        ListNode* cur = head;
        while(cur != nullptr && cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }

    void append(ListNode* head, int val) {
        ListNode* newTail = new ListNode(val);

        ListNode* cur = head;
        while(cur != nullptr) {
            if (cur->next == nullptr) {
                // find the tail node
                cur->next = newTail;
                break;
            }
            cur = cur->next;
        }        
    }

    void show(ListNode* head) {
        ListNode* ptr;
        ptr = head;
        while(ptr != nullptr) {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main() {
    Solution s;

    // build the singly linked list
    int a[] = {2, 6, 3, 4, 5, 6};
    vector<int> nums(a, a + sizeof(a)/sizeof(int));
    ListNode* test = new ListNode(1);
    for (int i = 0; i < nums.size(); i++) {
        s.append(test, a[i]);
    }
    s.show(test);

    // remove element whose value is val
    s.removeElements(test, 6);
    s.show(test);
    
    // head = [], val = 1
    // expected []
    ListNode* test2 = new ListNode(0);
    s.show(test2);
    s.removeElements(test2, 1);
    s.show(test2);

    // head = [7, 7, 7], val = 7
    //
    int b[] = {7, 7, 7};
    vector<int> nums2(b, b + sizeof(b)/sizeof(int));
    ListNode* test3 = new ListNode(7);
    for (int i = 0; i < nums2.size(); i++) {
        s.append(test3, b[i]);
    }
    s.show(test3);
    // remove element whose value is val
    s.removeElements(test3, 7);
    //s.show(test3);

    return 0;
}

