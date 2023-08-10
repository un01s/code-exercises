/**
 * Leetcode 450 
 *
 * BST, delet a node with the value and return the root
 * still return the root of BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
	// if not found, return

        if (root->val == key) {
            // if both left and right children empty, delete, return root
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            // if left child empty, right child not, delete,move right child up
            else if (root->left == nullptr) {
                TreeNode* ret = root->right;
                delete root;
                return ret;
            }
            // if left child not, right child empty, delete,move left child up
            else if (root->right == nullptr) {
                TreeNode* ret = root->left;
                delete root;
                return ret;
            }
            // both left and right not empty
            else {
                TreeNode* cur = root->right; // find the leftest of right sub
                while(cur->left != nullptr) {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
        }
        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;   
    }
};

int main() {
    return 0;
}
