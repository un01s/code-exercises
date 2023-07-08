# notes on intro to algorithms 4th ed.

## ch10 elementary data structures

### array

* linear, consecutive/continuous memory
* the same type of all elements
* 0-origin indexing or 1-origin indexing
* more static than dynamic due to its fixed size
* easy to access through index or pointer
* hard to resize an existing array

#### matrix

a matrix can be represented by a 1-dimensional or 2-dimensional array.

### stacks and queues

* dynamic data structure
* stack: last-in and first-out, or LIFO
* queue: first-in and first-out, or FIFO

| stacks | queues |
| ------ | ------ |
| last-in, first-out (LIFO) | first-in, first-out (FIFO) |
| same entry and exit point = stack.top | different entry and exit points = queue.head and queue.tail | 
| insert = PUSH, delete = POP | insert = ENQUEUE, delete = DEQUEUE | 

#### stacks

The stack has only one same entry and exit point. This is refered to the top of the stack. It's easy to use array to implement a stack of at most ```n``` elements. ```n``` is the size of the stack. The insert operation on a stack is often called push, and the delete operation POP.

When ```stack.top = 0```, the stack is empty. Upon an attempt to pop an empty stack, the stack underflows. If ```stack.top``` exceeds ```stack.size```, the stack overflows.

#### queues

Usually a stack allows insertion and deletion of elements at only one end (stack.top), and a queue allows insertion and deletion at the other end (tail for insertion, and head for deletion). There is a ```deque``` that is a double-ended queue. A deque allows insertion and deletion at both ends.

### linked list

A linked list is a data structure in which its elements are arranged in a linear order by its pointer in each element.

A singly linked list:

```C++
struct ListNode {
    int val; // key
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
```

A doubly linked list:

```C++
struct ListNode {
    int val; // key
    ListNode* next;
    ListNode* prev;
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};
```

The linked list may be either singly linked or doubly linked. It may be sorted or not based on the keys of its elements. It may be circular or not. 

