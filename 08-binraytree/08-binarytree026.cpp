/**
 * Leetcode 108 
 *
 * BST, array to heigh-balanced BST
 *
 * 2023-07-19
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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* traverse(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = (left+right)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = traverse(nums, left, mid-1);
        root->right = traverse(nums, mid+1, right);
        return root;
    }
    // range: [left, right] both ends are closed
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = traverse(nums, 0, nums.size()-1);
        return root;
    }
};

int main() {
    return 0;
}
