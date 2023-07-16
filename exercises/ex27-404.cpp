/*
 * leetcode 404
 * the sum of all left leaves
 *
 * what node is the left leaf?
 * if (node->left != nullptr  && node->left->left == nullptr &&
 *                               node->left->right == nullptr)
 *     
 * 
 * 2023-7-16
 *
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 0;
        int leftV = sumOfLeftLeaves(root->left);
        if (root->left && root->left->left == nullptr && root->left->right == nullptr) {
            leftV = root->left->val;
        }
        int rightV = sumOfLeftLeaves(root->right);
        int sum = leftV + rightV;
        return sum;
    }
};

class Solution2 {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftValue = 0;
        // left leaf
        if (root->left != nullptr && 
            root->left->left == nullptr && 
            root->left->right == nullptr) {
            leftValue = root->left->val;
        }
        return leftValue + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

int main() {
    Solution s;

    return 0;
}
