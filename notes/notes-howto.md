# how to study data structures and algorithm?

数据结构的基本存储方式就是链式和顺序两种，
基本操作就是增删查改，遍历方式无非迭代和递归。

## the storage of data structures

array (continuous) and linked list (list distributed)

## the operations on the data structure

traverse and visit: add/delete, check and modify.

linear or non-linear to traverse and visit.

```C++
void traverse(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        // linear traversing all elements of a vector or array
    }
}
```

For the linked-list, recursive or iterative.

```C++
struct ListNode {
    int val;
    ListNode next;
}; // singly linked-list

void traverse(ListNode* head) {
    for (ListNode* p = head; p != nullptr; p = p->next) {
        // iterative to get p->val;
    }
}

void traverse(ListNode* head) {
    // recursive
    traverse(head->next);
}
```

## how to do code exercises?

data structures are just tool. select appropriate tool to solve the problem.

### basic data structures and their common operations such as array, and linked list

### after the basics, start binary tree.

```
void traverse(TreeNode root) {
    // pre-order
    traverse(root.left);
    // in-order
    traverse(root.right);
    // post-order
}
```

Leetcode 124, 105, 

### then back-tracking, dynamic, etc. 
