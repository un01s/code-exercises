/**
 * Leetcode 110 balanced binary tree 
 *
 *
 * 2023-07-15
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
    int getHeight(TreeNode* node) {
        if (node == nullptr) return 0;
        // post-order traversal
        // check the left
        int hLeft = getHeight(node->left);
        if (hLeft == -1) return -1;
        // check the right
        int hRight = getHeight(node->right);
        if (hRight == -1) return -1;
        // mid
        int result = -1;
        if (abs(hLeft - hRight) <= 1) {
            result = 1 + max(hLeft, hRight);
        }
        return result;
    }
    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true; 
    }    
};

int main() {
    
    return 0;
}

