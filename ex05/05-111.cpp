/*
 * leetcode 111
 *
 */

class Solution {
public:
    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        int leftDepth = getDepth(node->left);           // left
        int rightDepth = getDepth(node->right);         // right
                                                        // mid
        // when a left subtree is empty, right not, not the lowest
        if (node->left == NULL && node->right != NULL) { 
            return 1 + rightDepth;
        }   
        // when a right subtree is empty but the left not, not the lowest
        if (node->left != NULL && node->right == NULL) { 
            return 1 + leftDepth;
        }
        int result = 1 + min(leftDepth, rightDepth);
        return result;
    }

    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};
