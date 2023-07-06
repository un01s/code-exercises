# recursive approach

this is an important technique and way to code. pay some attention to it.

TODO:
394 decode string

## three elements of a recursive implementation

* the input parameters and the return value of the recursive function
* the condition to terminate the recursion
* the logic of single recursion: what to do in this?

### pre-order traversal of a binary tree

There are several ways to traverse a binary tree: pre-order, in-order, post-order, depth-first, and breadth-first.

In pre-order traversal, visit the current node, next recursively traverse the left subtree of current node, then recursively treverse the right subtree of current node.

1. ```void traversal(TreeNode* cur, vector<int>& v)```

Input vector is used to store the value of the node. No return value.

2. when to terminate the recursion? 

```C++
if (cur == nullptr) return;
```

3. the logic in a single step

```C++
v.push_back(cur->val);
traversal(cur->left, v);
traversal(cur->right, v);
```

The complete code for pre-order traversal is as follows:

```C++
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    // constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& v) {
        if (cur == nullptr) return;
        v.push_back(cur->val); // mid
        traversal(cur->left, v); // left
        traversal(cur->right, v); // right
    }
    vector<int> preOrderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
```

TODO: 144 (pre-order), 145 (post-order), 94 (in-order)

