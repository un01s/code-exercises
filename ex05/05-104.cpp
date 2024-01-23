/*
 * leetcode 104
 *
 */

class solution {
public:
    int result;
    void getdepth(TreeNode* node, int depth) {
        result = depth > result ? depth : result; // mid

        if (node->left == NULL && node->right == NULL) return ;

        if (node->left) { // left
            depth++;    // depth+1
            getdepth(node->left, depth);
            depth--;    // back, depth-1
        }
        if (node->right) { // right
            depth++;    // depth+1
            getdepth(node->right, depth);
            depth--;    // back, depth-1
        }
        return ;
    }
    int maxDepth(TreeNode* root) {
        result = 0;
        if (root == NULL) return result;
        getdepth(root, 1);
        return result;
    }
};
