/**
 * Leetcode 222 
 *
 *
 * 2023-07-15
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // treat the complete binary tree as an ordinary binary tree
    int getNum(TreeNode* node) {
        if (node == nullptr) return 0;
        int left = getNum(node->left);
        int right = getNum(node->right);
        return 1+left+right;
    }
    int countNodes(TreeNode* root) {
        return getNum(root);
    }    
};

int main() {
    
    return 0;
}

