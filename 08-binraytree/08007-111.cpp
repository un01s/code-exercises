/**
 * Leetcode 111  
 *
 * depth of a node: 
 * the number of nodes on the longest path from the root to this node
 *
 * height of a node:
 * the number of nodes on the longest path from this node to a leaf node
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
    int getDepth(TreeNode* node) {
        // the condition to stop the recursion
        if (node == nullptr) return 0;
        // 
        int left = getDepth(node->left);
        int right = getDepth(node->right);
        if (node->left == nullptr && node->right != nullptr) {
            return 1 + right;
        }
        if (node->left != nullptr && node->right == nullptr) {
            return 1 + left;
        }
        return 1+min(left, right);
    }

    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};

int main() {
    
    return 0;
}

