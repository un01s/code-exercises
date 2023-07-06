# binary tree

## types of binary tree

* full binary tree,  one in which every node has either 0 or 2 children.

* perfect binary tree, one in which all interior nodes have two children and all leaves have the same depth or same level.

* complete binary tree

* binary search tree

* balanced binary search tree

## storage of binary tree

either linked-list or array

## traverse of binary tree

depth vs. breadth

## binary tree

```C++
struct TreeNode {
    int val;
    TreeNode *left;    
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}    
};
```

