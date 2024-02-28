/*
 * leetcode 513
 * find bottom left tree value
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
    using info=pair<TreeNode*, int>;
    int findBottomLeftValue(TreeNode* root) {
        // BFS
        int res = 0;
        int level = -1;
        queue<info> q;
        q.emplace(root, 0);
        while(!q.empty()) {
            auto [node, h] = q.front();
            q.pop();
            if (!node) continue;
            if (h >= level) {
                res = node->val;
                level = h;
            }
            q.emplace(node->right, h+1); 
            q.emplace(node->left, h+1);
        }
        return res;
    }
};

