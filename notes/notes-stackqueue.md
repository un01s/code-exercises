# stack and queue

Stack: first-in-last-out 
Queue: first-in-first-out

* What is the container for stack in C++?
* which version of STL does stack use?
* how STL implements stack?
* what is the iterator for stack?

## versions of STL for stack and queue

* HP STL, open source
* P.J Plauger STL, for Visual C++
* SGI STL, for Linux GCC, open source

Stack in STL is a container adapter instead of container. It utilizes the low-level container to implement all the work and provides a unified interface. So the low-level container is pluggable and replaceable.

Stack has the interfaces of pop, push, top and others, and has no iterator.

SGI STL uses deque to implement stack. Deque (deck) is a double-ended queue. Deque is an abstract data structure that generalizes a queue. Elements of deque can be added to or removed from either the front (head) or back (tail). It is also called a head-tail linked list.

Queue in SGI STL uses deque as the low-level container.
 
Stack can be implemented using vector. Queue can be implemented with list.

## queue vs priority queue

| queue | priority queue |
| ----- | -------------- |
| FIFO  | highest priority out first |
| the internal order of insertion maintained | the insertion order changed by priority |

## priority queue

By default, STL priority_queue gives the largest element the highest priority.

| member function | notes |
| --------------- | ----- |
| empty() | if the priority queue is empty or not |
| size() | the total number of elements in the priority queue |
| top() | get the element with the highest priority in the queue |
| push() | insert an element (a copy) in the priority queue |
| pop() | remove the top element in the queue |
| swap() | swap the elements of one priority queue with another |
| emplace() | add a new element (new instance) to the queue at the top |

## use-cases of a priority queue

* prim's algorithm
* Dijkstra's shortest path algorithm
* heap sort
* data compression
* A* search algorithm

The priority queue in C++ is by default implemented using the internal max-heap structure. However, a min-heap can also be created to implement the priority queue.


## [232 use stack to implement queue](https://leetcode.com/problems/implement-queue-using-stacks/)

## Leetcode 239 and 347

* 239

Try this with the sliding-window approach, but can't get it right completely. The need to have to track all the values in the window is complicated. When the monotonic queue is used, the solution is quite elegant.

* 347

this uses the max-heap (complete binary tree). Need to spend more time on this and to understand the details of all implementations and theory too.


