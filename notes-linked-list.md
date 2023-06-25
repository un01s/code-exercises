# note on [linked list](https://en.wikipedia.org/wiki/Linked_list)

A linked list is a linear collection of data elements and each element points to the next. The simplest is a data structure of a collection of nodes and each node has data and a reference, which is a pointer to next node. 

* singly linked list

```c++
struct ListNode {
    int val; // node data
    ListNode *next; // pointer to the next node
    ListNode(int x): val(x), next(nullptr) {} // constructor
};

ListNode* head = new ListNode(1);
```

* doubly linked list

## array vs linked list

array has the continuous space in memory, while a linked list is not continuous in the memory and each node is only connected with another through its reference pointer.

## operations on linked list

* delete a node

* add a node

## notes

In [Leetcode 19: remove the Nth node from end of list](https://leetcode.com/problems/remove-nth-node-from-end-of-list/):

* use the dummy head so that both head-node and non-head-node could be treated in the same way
* use double-pointer approach: 
  *  move the fast pointer n+1 nodes/steps
  * then move both fast and slow pointers until the fast is pointing at the tail. the slow pointer is pointing at the node just before the Nth from the end
* this approah is clever to use the double pinters

In [leetcode 160: intersection of two linked lists](https://leetcode.com/problems/intersection-of-two-linked-lists/), the solution has an interesting idea: get the length of both lists and move one pointer so that both are tail-aligned. Then move both pointers at the same time to find if there is an intersection. That is, if the pointer has the same value.

In [leetcode 142: linked list cycle II](https://leetcode.com/problems/linked-list-cycle-ii/), there are some math required.

The approach is to use double pointers. Both pointers start from the head node, the fast pointer moves two nodes while the slow pointer moves one node at a time. If both pointers met, then there is a circle or ring. 

How to find out the entry node? 

* x: from the head node to the entry node
* y: from the entry node to the meeting node
* z: from the meeting node to the entry node

So the slow pointer moves ```x + y``` steps/nodes when both meet. The fast pointer has ```x + y + n*(y + z)``` where ```n >= 1```.

The equation is ```(x + y)*2 = x + y + n*(y + z)```. To find the entry node, x is the answer. Follow the equation, ```x + y = n* (y + z)```, then ```x = n*(y + z) - y```. If n = 1, then ```x = z```.

Now if we have two pointers, if one starts from the head node, and the other starts from the met node, when these two pointer met, it is where the entry node is.

