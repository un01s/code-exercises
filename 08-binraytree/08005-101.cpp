/**
 * Leetcode 101 symmetric binary tree? 
 *
 *
 * 2023-07-13
 *
 * TODO 100
 * TODO 572
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // recursive
    bool compare(TreeNode* left, TreeNode* right) {
        // if there is a null node
        if (left == nullptr && right != nullptr) return false;
        else if (left != nullptr && right == nullptr) return false;
        else if (left == nullptr && right == nullptr) return true;
        // both NOT null, check if the value equals
        else if (left->val != right->val) return false;

        // both left and right are not NULL, their values are equal too
	// prep for next level
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool isSame = outside && inside;

        return isSame;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return root;
        return compare(root->left, root->right);
    }    
};

int main() {
    
    return 0;
}

