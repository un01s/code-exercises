# double-pointer approach for linked list

## TODO

* [141. Linked list cycle](https://leetcode.com/problems/linked-list-cycle/)

* [142. Linked list cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)

* [160. intersection of two linked lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)

* [19. remove Nth node from end of list]()

* [21. merge two sorted lists](https://leetcode.com/problems/merge-two-sorted-lists/)

* [23. merge K sorted lists](https://leetcode.com/problems/merge-k-sorted-lists/)

* [86. partition list](https://leetcode.com/problems/partition-list/)

* [876. middle of the linked list](https://leetcode.com/problems/middle-of-the-linked-list/)

## recursive

To understand the recursive algorithm, there are a few things to note:

* what is the definition of the recursive function?

* what is the termination condition to stop the recursion?

### Leetcode 206 reverse the linked list

```C++
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // this recursion starts from the very end, and moves to the start
    // tail to head
    //
    // the definition of reverseList function:
    // input: one head node
    // output: the head node after reversal
    ListNode* reverse(ListNode* head) {
        ListNode* reverseList(ListNode* head) {
        // termination condition: when the recursive should stop
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* last = reverseList(head->next);

        // according to the function definition
        // now the last is the new head
        // and the head->next is the new tail
        head->next->next = head;
        head->next = nullptr;

        return last;    
    }
};
```

### reverse the first N nodes

```
reverseN(head, 3):

1 -> 2 -> 3 -> 4 -> 5 -> nullptr
1 -> 2 -> 3    4 -> 5 -> nullptr
          ^
3 -> 2 -> 1 -> 4 -> 5 -> nullptr         
```

```C++
class Solution {
public:
    ListNode* nodeN; // counting start from 0
    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {
            nodeN = head->next;
            return head;
        }
        // start from head->next, have to reverse the first n-1 nodes
        ListNode* last = reverseN(head->next, n-1);

        head->next->next = head;
        head->next = nodeN;
        return last;
    }
};
```

### reverse a part of a linked list

* [leetcode 92 reverse linked list II](https://leetcode.com/problems/reverse-linked-list-ii/)

```C++
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // base case or termination condition
        if (m == 1) {
            return reverseN(head, n);
        }
        // trigger the base case
        head->next = reverseBetween(head->next, m-1, n-1);
        return head;
    }
    // leetcode  
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // base case or termination condition
        if (left == 1) {
            return reverseN(head, right);
        }
        // trigger the base case
        head->next = reverseBetween(head->next, left-1, right-1);
        return head;    
    }
};
```

