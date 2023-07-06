# notes on array

For the loops, always remember to maintain correct range of either [start, end) or (start, end]. This is extremely important in the loop. Find it and keep it constant. A ```loop invariant``` is some predicate (condition) that holds for every iteration of the loop. 

```c++
int s = 0;
for (int i = 0; i < a.size(); i++) {
    // s is the sum of the first i elements
    s = s + a[i];
}
```

## array vs vector in C++

All the code in C++ uses vector instead of array in LeetCode. Though vector is based on array, they are different.

### array

* built-in language construct
* a continuous, indexable sequence of the same-type elements
* fixed size (no resize), compile-time constant unless allocated dynamically
* the storage space is scoped
* if dynamically allocated, deallocate them explicitly, atomic allocation

### vector

* a template class
* c++ only contruct
* implemented as a dynamic array, changeable

## notes on 02-array006.cpp [54 spiral matrix](https://leetcode.com/problems/spiral-matrix/)

Before this problem, all the solutions are from others. This code is all by myself.

* this is a more general problem than [59 spiral matrix II](https://leetcode.com/problems/spiral-matrix-ii/). Here the matrix is about m x n. This is more complex than the matrix of n x n.

* follow the solution of n x n matrix, it is easy to deal with different row and column numbers. For the row, one side has the range of [starty, col-1). For the column, one side has the range of [startx, row-1). We have to keep the range with its left closed and its right open. This is important in the loops.

* One complete loop has to go four sides one after another. The first from left to right [starty, col-1) increment, the second from top to bottom [startx, row-1) increment, the third from right to left [starty, col-1) decrement, and the fourth from bottom to top [startx, row-1) decrement. The starting point of one complete loop is ``` [startx, starty]```, the length of one row is ```row```, and the length of one column is ```col```.

* For nxn matrix, the loop is always a complete one with four loops. One possible corner case is that when the edge is an odd number, there is the center of the matrix has to be taken care of separately. 

* However, for mxn matrix, there are more corner cases. There are cases of small matrix which does not have a complete loop such as [[1]], 1xn or mx1 matrix. There are cases of how to deal with remaining grids after some complete loops. the remaining may be one element at the center of the matrix, one row or one column.

## algorithms used with array

* binary search: O(logN)

* double pointers (fast and slow pointers)

* sliding window (adjusting the start position of sub-string)

## reference

* [loop invariant](https://en.wikipedia.org/wiki/Loop_invariant)

