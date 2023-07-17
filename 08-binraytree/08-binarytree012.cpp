/**
 * Leetcode 112 
 *
 *
 * 2023-07-17
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool traverse(TreeNode* cur, int count) {
        // use minus instead of addition
        // at the end both count == 0 and the node is a leaf
        if (!cur->left && !cur->right && count == 0) return true;
        // it is a leaf but count != 0
        if (!cur->left && !cur->right) return false; 
        // continue to left
        if (cur->left) { 
            if(traverse(cur->left, count-cur->left->val)) return true;
        }
        // countinue to right 
        if (cur->right) { 
            if(traverse(cur->right, count-cur->right->val)) return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        return traverse(root, sum - root->val);
    }    
};

int main() {
    
    return 0;
}

