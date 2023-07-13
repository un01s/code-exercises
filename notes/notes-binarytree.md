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

use stack to traverse a binary tree : depth-first (recursive)
use queue to traverse a binary tree : breadth-first

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

* [144 preorder traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)
* [94 inorder traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)
* [145 postorder traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)
* [level order traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)
* [zigzag level traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
* [level order traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)

use queue iteratively for level order traversal.

1. construct a queue with TreeNode, ```queue<TreeNode* > q;```, initially push the given root in it
2. iterate through the queue until empty
    1. store the current size of queue ```tempSize```, this will be the size of the current level of the tree.
    2. now traverse this level for ```tempSize>=0```: pop the current element and apply the needed operation for the same and if left or right child exist then pass them to the queue.

Check out [this binary problem list](https://leetcode.com/discuss/study-guide/1212004/Binary-Trees-study-guide).

#### pre-order iterative traversal with stack

```C++
class Solution {
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        // the order of traversal and processing is the same
        if (root == nullptr) return result;
        st.push(root); // mid, left, right
        while(!st.empty()) {
            TreeNode* node = st.pop();
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return result;
    }
};
```

#### in-order iterative traversal

```C++
class Solution {
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        // the order of traversal and processing is different
        // 1. processing: put val into result
        // 2. traverse nodes
        TreeNode* cur = root;
        while(cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur); // traverse till the end
                cur = cur->left; // left
            } else {
                cur = st.top(); // get the node from the stack to process
                st.pop();
                result.push_back(cur->val); // mid
                cur = cur->right; // right
            }
        }
        return result;
    }
};
```

#### post-order iterative traversal

```C++
class Solution {
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == nullptr) return result;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val); // mid
            if (node->left) st.push(node->left); // left
            if (node->right) st.push(node->right); // right 
        }
        reverse(result.begin(), result.end()); // to get left, right, mid
        return result;
    }
};
```
## binary search tree

### BST is a sorted or ordered binary tree. 

* if its left sub-tree is not empty, the values of all left sub-tree nodes are less than its root value
* if its right sub-tree is not empty, the values of all right sub-tree nodes are greater than its root value
* both left sub-tree and right sub-tree are BST too

### balanced BST (AVL tree)


