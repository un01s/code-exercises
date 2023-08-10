/**
 * Leetcode 104 maximum depth of binary tree 
 *
 * Given the root of a binary tree, return its maximum depth.
 *
 * A binary tree's maximum depth is the number of nodes along the longest path 
 * from the root node down to the farthest leaf node.
 *
 * 2023-07-14
 *
 * TODO 559 
 * TODO 
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
    int getDepth(TreeNode* node) {
        if (node == nullptr) return 0;
        // find the depth of left-sub-tree, right-sub-tree, max
        int leftDepth = getDepth(node->left); // left
        int rightDepth = getDepth(node->right); // right
        int depth = max(leftDepth, rightDepth) + 1; // mid
        return depth;
    }
    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }
};

int main() {
    
    return 0;
}

