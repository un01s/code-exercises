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

It is troublesome to get a specific node while dealing with a singly linked list. It is common to use ```while(cur->next != nullptr)``` to traverse the whole list. Then use ```while(index--)``` to reach a specific node at the index. 

The first problem, [203 remove linked list elements](https://leetcode.com/problems/remove-linked-list-elements/), is easy. Just get the struct of list node reight. Then traverse the list to match the value of a node with the expected value. 
The second problem is [707 design linked list](https://leetcode.com/problems/design-linked-list/). DummyHead is to make the programmer's life easier. Basic operations on the linked list are there. Then how to test the code if we are not rely on the leetcode. How to cover the code with complete cases is another problems.

### [leetcode 206: reverse linked list](https://leetcode.com/problems/reverse-linked-list/)

### [leetcode 24: swap nodes in pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)

After this, another problem [leetcode 1721: swapping nodes in a linked list](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/). It is always handy if you get the pointer to the node just before the node to operate in a singly linked list.

### [Leetcode 19: remove the Nth node from end of list](https://leetcode.com/problems/remove-nth-node-from-end-of-list/):

* use the dummy head so that both head-node and non-head-node could be treated in the same way

* use double-pointer approach: 
  *  move the fast pointer n+1 nodes/steps
  * then move both fast and slow pointers until the fast is pointing at the tail. the slow pointer is pointing at the node just before the Nth from the end
* this approah is clever to use the double pinters

### [leetcode 160: intersection of two linked lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)

the solution has an interesting idea: get the length of both lists and move one pointer so that both are tail-aligned. Then move both pointers at the same time to find if there is an intersection. That is, if the pointer has the same value.

### [leetcode 142: linked list cycle II](https://leetcode.com/problems/linked-list-cycle-ii/), there are some math required.

The approach is to use double pointers. Both pointers start from the head node, the fast pointer moves two nodes while the slow pointer moves one node at a time. If both pointers met, then there is a circle or ring. 

How to find out the entry node? 

* x: from the head node to the entry node
* y: from the entry node to the meeting node
* z: from the meeting node to the entry node

So the slow pointer moves ```x + y``` steps/nodes when both meet. The fast pointer has ```x + y + n*(y + z)``` where ```n >= 1```.

The equation is ```(x + y)*2 = x + y + n*(y + z)```. To find the entry node, x is the answer. Follow the equation, ```x + y = n* (y + z)```, then ```x = n*(y + z) - y```. If n = 1, then ```x = z```.

Now if we have two pointers, if one starts from the head node, and the other starts from the met node, when these two pointer met, it is where the entry node is.

