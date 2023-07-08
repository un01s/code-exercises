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

## pre-order, in-order, and post-order traversal

| pre-order | in-order | post-order |
| --------- | -------- | ---------- |
| mid ->left ->right | left ->mid ->right | left ->right ->mid |
| a, b, d, e, c, f, g| d, b, e, a, f, c, g| d, e, b, f, g, c, a|

So the order is based on the mid node (or root node).

![binary-tree](https://github.com/un01s/code-exercises/blob/main/media/binary-tree.png)

## problems of binary tree

### traversal

* [preorder traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)
* [inorder traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)
* [postorder traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)
* [level order traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)
* [zigzag level traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
* [level order traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)

use queue iteratively for level order traversal.

1. construct a queue with TreeNode, ```queue<TreeNode* > q;```, initially push the given root in it
2. iterate through the queue until empty
    1. store the current size of queue ```tempSize```, this will be the size of the current level of the tree.
    2. now traverse this level for ```tempSize>=0```: pop the current element and apply the needed operation for the same and if left or right child exist then pass them to the queue.

Check out [this binary problem list](https://leetcode.com/discuss/study-guide/1212004/Binary-Trees-study-guide).

