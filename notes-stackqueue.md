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

## [232 use stack to implement queue](https://leetcode.com/problems/implement-queue-using-stacks/)


