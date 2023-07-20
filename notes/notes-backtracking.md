# back tracking

back tracking is one of search approach. Like the tree traversal, sometimes it goes to the leaf node, then it back from there recursively. In many problems of binary tree traversal, the solution usually has both recursion and back tracking.

A recursive function usually has the back tracking within it.

However, back tracking is close to brute force and not so efficient in its search.

## the problems solved by back tracking

* combination: get k from N numbers, order is not of concern usually
* substring
* subset
* permutation: order is important
* checkboard: sudoko, etc.

## how to think about back tracking

the solution can always be abstracted as tree structure.
the problem is always find subsets recursively in one set, the size of set is the width of tree, the depth of recursion is the tree depth.

To stop the recursion, there must be a condition, then the tree must have limited height.

## three steps of recursive template

* the recursive function: its return or no return and its parameters
* how to stop the recursion: the condition or conditions to stop it
* the single loop to process, store, etc.

for-loop is used for breadth traversal, backtracking is for depth traversal.

```
void backtracking(params) {
    if (stop-condition) {
        store results;
        return;
    }

    for(choose element in the set) {
        process the node;
        backtracking(path, list, etc.); // recursive
        // back, reverse, etc.
    }
}
```

