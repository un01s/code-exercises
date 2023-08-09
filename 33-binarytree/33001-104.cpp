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

class Solution2 {
pulic:
    int res = 0; // max depth
    int depth = 0; // depth of traversal
    // recursively
    void traverse(TreeNode* cur) {
        if (cur == nullptr) return;
        // preorder
        depth++;
        if (cur->left == nullptr && cur->right == nullptr) {
            res = max(res, depth);
        }
        traverse(cur->left);
        traverse(cur->right);
        depth--;
    }

    int maxDepth(TreeNode* root) {
        traverse(root);
        return res;
    }
};

// the max depth of a binary tree can be derived from 
// the max depth of its subtrees
//
class Solution3 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftMax = maxDepth(root->left);    
        int rightMax = maxDepth(root->right);
        // max depth of a tree =
        // max(leftMax, rightMax) + 1 (root itself)
        int res = max(leftMax, rightMax) + 1;
        // this is a typical postorder traversal
        // because first we have to get max depth of its subtrees
        // then back to the root to crunch the number
        return res;   
    }
};

int main() {
    
    return 0;
}

