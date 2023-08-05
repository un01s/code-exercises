# basics

The base of data structures are array and linked list. All other data structures could be built upon either array or linked list.

The operations on one data structure are simply the following:

* add/insert
* delete
* check/traverse: for/while array (linear) 
* replace

How to perform these operations efficiently is the core to choose different data structures and its algorithms.

To solve a problem, the key is to exhaust all possible paths or answers, no duplicates, no redundants, then choose the correct one.

## [leetcode 124 binary tree max path sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = INT_MIN;
    int oneSideMax(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = max(0, oneSideMax(root->left));
        int right = max(0, oneSideMax(root->right));
        res = max(res, left + right + root->val);
        
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        oneSideMax(root);
        return res;    
    }
};
```


