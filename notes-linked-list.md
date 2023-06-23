# note on [linked list](https://en.wikipedia.org/wiki/Linked_list)

A linked list is a linear collection of data elements and each element points to the next. The simplest is a data structure of a collection of nodes and each node has data and a reference, which is a pointer to next node. 

* singly linked list

```c++
struct ListNode {
    int val; // node data
    ListNode *next; // pointer to the next node
    ListNode(int x): val(x), next(NULL) {} // constructor
};

ListNode* head = new ListNode(1);
```

* doubly linked list

## array vs linked list

array has the continuous space in memory, while a linked list is not continuous in the memory and each node is only connected with another through its reference pointer.

## operations on linked list

* delete a node

* add a node

