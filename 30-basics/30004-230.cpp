/*
 * Leetcode 230
 * kth smallest element in a BST
 *
 * Given the root of a binary search tree, and an integer k, return the kth 
 * smallest value (1-indexed) of all the values of the nodes in the tree.
 * 
 * input: root = [3, 1, 4, null, 2], k = 1
 * output: 1
 *
 * input: root = [5, 3, 6, 2, 4, null, null, 1], k = 3
 * output: 3
 *
 *
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int count = 0;
    int res = 0;
    void traverse(TreeNode* cur, int k) {
        if (cur == nullptr) return;

        traverse(cur->left, k);
        count++;
        if (k == count) {
            res = cur->val;
            return;
        }
        traverse(cur->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) return -1;
        traverse(root, k);
        return res;
    }
};


