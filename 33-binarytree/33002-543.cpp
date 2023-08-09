/*
 * leetcode 543
 * diameter of binary tree
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
    int maxDiameter = 0;
    int maxDepth(TreeNode* cur) {
        if (cur == nullptr) return 0;
        int leftMax = maxDepth(root->left);
        int rightMax = maxDepth(root->right);
        return max(leftMax, rightMax)+1;
    }
    void traverse(TreeNode* cur) {
        if (cur == nullptr) return;
        // start for every node
        int leftMax = maxDepth(cur->left);
        int rightMax = maxDepth(cur->right);
        int diameter = leftMax + rightMax;
        maxDiameter = max(maxDiameter, diameter);
        //
        traverse(cur->left);
        traverse(cur->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root);
        return maxDiameter;
    }
};

// simplify the above
class Solution2 {
public:
    int maxDiameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxDiameter;
    }
    int maxDepth(TreeNode* cur) {
        if (cur == nullptr) return 0;

        int leftMax = maxDepth(cur->left);
        int rightMax = maxDepth(cur->right);

        int diameter = leftMax + rightMax;
        maxDiameter = max(maxDiameter, diameter);

        return max(leftMax, rightMax)+1;
    }
};

int main() {
    return 0;
}
