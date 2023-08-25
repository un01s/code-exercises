# Data Structures and Algorithms

## basics

The fundamental structures are ```array``` and ```linked list```. The basic operations on any data structure are as follows: 
 
| Operation | Array | Linked List |
| -- | ----- | ----------- |
| READ: access to one element | index | Traverse |
| WRITE: modify one element | index | Traverse |
| SEARCH: look for one specific element | index | Traverse |
| ADD: add one new element | resize | pointer |
| MINUS: remove one existing element | move | pointer |

After both ```array``` and ```linked list```, ```string```, ```stack``` and ```queue``` are natural variants of ```array```. Then ```binary tree``` expands ```linked list```. 

```C++
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traverse(TreeNode* root) {
    // pre-order
    traverse(root->left);
    // in-order
    traverse(root->right);
    // post-order
}
```

