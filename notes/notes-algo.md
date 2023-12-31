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

For the singly linked list, the head node is bit different from the other nodes. In actual code, introducing **a virtual head** makes all nodes the same.

The pseudo code below is all about operations on a doubly linked list.

#### searching a linked list

```C++
ListNode* list-search(ListNode* head, int key) {
    ListNode* x = head;
    while (x != nullptr && x.val != key) {
        x = x.next;
    }
    return x;
}
```

#### inserting into a linked list

Do we still need to maintain a head of a linked list?

```C++
void list-prepend(ListNode* head, ListNode x) {
    x.next = head;
    x.prev = nullptr; // doubly-linked list
    if (head != nullptr) {
        head->prev = &x;
    }
    head = &x;
}
```

the following insert one element x right after y

```C++
void list-insert(ListNode* x, ListNode* y) {
    x->next = y->next;
    x->prev = y;
    if (y->next != nullptr) {
        y->next.prev = x;
    }
    y->next = x;
}
```

#### deleting from a linked list

```C++
void list-delete(ListNode* head, ListNode x) {
    if (x.prev != nullptr) {
        x.prev.next = x.next;
    } else {
        head = x.next;
    }
    if (x.next != nullptr) {
        x.next.prev = x.prev;
    }
}
```

#### sentinels basically are virtual head nodes to simplify the code

#### exercise

* 10.2-2 implement a stack using a singly linked list
* 10.2-3 implement a queue using a singly linked list

### rooted trees

Linked lists work well for representing linear relationahip. But no all relationships are linear.

#### binary tree

Each element or node has the attributes **p**, **left** and **right** for pointers to store the parent, left child, adn right child. If ```x.p == nullptr```, then x is the root. If ```x.left ==  nullptr```, then the node x has no left child.

 
