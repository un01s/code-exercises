/*
 * leetcode 23
 * merge K ordered linked list (ascending)
 *
 * Q: when to use the dummy head? 
 * A: when there is a need to create a new linked list.
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

//
class Solution {
public:
    ListNode* mergeKLists(ListNode[] lists) {
        if (lists.size() == 0) return nullptr;

        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;

        auto comp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        PriorityQueue<ListNode*, vector<ListNode*>, declty(comp)> pq(comp);

        for (ListNode node : lists) {
            if (node != nullptr) {
                pq.add(node);
            }
        }
        while (!pq.empty()) {
            ListNode* tmp = pq.top();
            pq.pop();
            p->next = tmp;
            p = p->next;
            if (tmp->next != nullptr) {
                pq.push(tmp->next);
            }
        }
        return dummy->next;
    }
};
