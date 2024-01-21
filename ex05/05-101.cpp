/*
 * leetcode 101
 *
 */

class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        // empty node
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        // 
        else if (left->val != right->val) return false;

        // both left and right are not empty, with the same value
        bool outside = compare(left->left, right->right);   // 
        bool inside = compare(left->right, right->left);    //
        bool isSame = outside && inside;                    //
        return isSame;

    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return compare(root->left, root->right);
    }
};
