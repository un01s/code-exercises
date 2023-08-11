/*
 * leetcode 226
 * invert binary tree
 *
 */

#include <iostream>

using namespace std;

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

int main() {
    return 0;
}
