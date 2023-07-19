/**
 * Leetcode 701 
 *
 * BST, insert a value and return the root
 *
 * 2023-07-19
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* parent;
    void traverse(TreeNode* cur, int val) {
        // find a null, insert and return
        if (cur == nullptr) {
            TreeNode* node = new TreeNode(val);
            if (val > parent->val) {
                parent->right = node;
            } else {
                parent->left = node;
            }
            return;
        }
        parent = cur;
        if (cur->val > val) traverse(cur->left, val);
        if (cur->val < val) traverse(cur->right, val);
        return;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // empty tree
        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }
        // not empty BST
        parent = new TreeNode(0);
        traverse(root, val);
        return root;
    }
};

class Solution2 {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // if the node is empty
        TreeNode* node = new TreeNode(0);
        if (root == nullptr) {
            node->val = val;
            root = node;
        }
        // the root is not empty
        // BST, go left
        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        }
        // BST go right
        if (root->val < val) {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

int main() {
    return 0;
}
