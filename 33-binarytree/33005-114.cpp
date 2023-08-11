/*
 * leetcode 114
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
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        // flatten both left and right subtrees
        flatten(root->left);
        flatten(root->right);

        // postorder
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        // make the left sub as the right
        root->left = nullptr;
        root->right = left;
        // connect previous right subtree connecting to 
        // the end of current right sub
        TreeNode* p = root;
        while (p->right != nullptr) {
            p = p->right;
        }
        p->right = right;
    }
};

class Solution2 {
public:
    TreeNode* prev = nullptr;

    void traverse(TreeNode* cur) {
        if (cur == nullptr) return;
        //
        traverse(cur->right);
        traverse(cur->left);
        cur->right = prev;
        cur->left = nullptr;
        prev = cur;
    }
    void flatten(TreeNode* root) {
        traverse(root);    
    }
};
