# [dynamic programming](https://en.wikipedia.org/wiki/Dynamic_programming)

* optimal substructure (local optimal leading to global optimal)
* overlapping subproblems 

if a problem can be solved by combing optimal solutions to non-overlapping sub-problems, the strategy is called "divid and conquer" instead. This is why merge sort and quick sort are not classified as dynamic programming problems.

## some examples

### Dijkstra's algo for shortest path problem

### fibonacci sequence

### A type of balanced 0-1 matrix

### checkerboard

### sequence alignment

### tower of hanoi puzzle

### egg dropping puzzle

### leetcode 123

| dp[i][j] | state j = 0 | 1 | 2 | 3 | 4 |
| -------- | ----------- | - | - | - | - |
| index i = 0 | 0 | -1 | 0 | -1 | 0 |
| 1 | 0 | -1 | 1 | -1 | 1 |
| 2 | 0 | -1 | 2 | -1 | 2 | 
| 3 | 0 | -1 | 3 | -1 | 3 |
| 4 | 0 | -1 | 4 | -1 | 4 |



