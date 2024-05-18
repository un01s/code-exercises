/*
 * leetcode 979
 * distribute coins in binary tree
 *
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int move = 0;
    int rec(TreeNode* root) {
        if (!root)
            return 0;
        int l = rec(root->left);
        int r = rec(root->right);
        int totalNeed = root->val - 1 + l + r;
        move += abs(totalNeed);
        return totalNeed;
    }
    int distributeCoins(TreeNode* root) {
        rec(root);
        return move;
    }
};

