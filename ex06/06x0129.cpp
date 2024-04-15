/*
 * leetcode 129
 * sum root to leaf numbers
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    void fn(TreeNode* node, int digit) {
        if (!node) return;
        digit = node->val + 10*digit;
        if (!node->left && !node->right) sum += digit;
        fn(node->left, digit);
        fn(node->right, digit);
    }
    int sumNumbers(TreeNode* root) {
        fn(root, 0);
        return sum;
    }
};

// DFS
class Solution2 {
public:
    int sumNumbers(TreeNode* root) {
        vector<pair<TreeNode*, int>> stack = {{root, 0}};
        int sum = 0;
        TreeNode* node = root;
        while (!stack.empty()) {
            auto [node, d] = stack.back();
            stack.pop_back();
            d = 10 * d + node->val;
            if (!node->left and !node->right)
                sum += d;
            if (node->right)
                stack.emplace_back(node->right, d);
            if (node->left)
                stack.emplace_back(node->left, d);
        }
        return sum;
    }
};
