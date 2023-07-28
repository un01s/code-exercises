/*
 * leetcode 968
 * binary tree cameras
 * 
 * You are given the root of a binary tree. We install cameras on the tree 
 * nodes where each camera at a node can monitor its parent, itself, and its 
 * immediate children.
 *
 * Return the minimum number of cameras needed to monitor all nodes of the tree.
 */

#include <iostream>
#include <vector>

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
    int res;
    int traverse(TreeNode* cur) {
        // empty
        if (cur == nullptr) return 2;
        
        int left = traverse(cur->left);
        int right = traverse(cur->right);

        // both left and right
        if (left == 2 && right == 2) return 0;

        if (left == 0 || right == 0) {
            res++;
            return 1;
        }
 
        if (left == 1 || right == 1) return 2;

        return -1;
    }
    int minCameraCover(TreeNode* root) {
        res = 0;
        if (traverse(root) == 0) {
            res++;
        }
        return res;        
    }
};

int main() {
    return 0;
}
