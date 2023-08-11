/*
 * leetcode 226
 * invert binary tree
 *
 */


class Solution {
public:
    void traverse(TreeNode* cur) {
        if (cur == nullptr) return;
        
        TreeNode* tmp = cur->left;
        cur->left = cur->right;
        cur->right = tmp;
        
        traverse(cur->left);
        traverse(cur->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        traverse(root);
        return root;    
    }
};

class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;

        TreeNode* left = invertTree(root->left);    
        TreeNode* right = invertTree(root->right);

        root->left = right;
        root->right = left;

        return root;    
    }
};
