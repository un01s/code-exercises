/**
 * Leetcode 654 
 *
 * construct a max binary tree
 * 
 * root has the max value always
 * left sub-tree is constructed by the left part of the max
 * right sub-tree is constructed by the right part of the max
 * 
 * 
 * 2023-07-18
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
    void print(vector<int>& v) {
        cout << ":";
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << " "; 
        }
        cout << endl;
    }

    TreeNode* constructMaxBinaryTree(vector<int>& nums) {
        TreeNode* node = new TreeNode(0);
        // the condition to stop is find the leaf node!
        if (nums.size() == 1) {
            // this tree has only one node
            node->val = nums[0];
            return node;
        }
        // find the max and its index
        int maxV = 0;
        int maxIndex = 0;
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxV) {
                maxV = nums[i];
                maxIndex = i;
            }
        }
        node->val = maxV;

        // there are elements in the left side of maxV
        if (maxIndex > 0) {
            vector<int> leftVec(nums.begin(), nums.begin()+maxIndex);
            node->left = constructMaxBinaryTree(leftVec); 
        }
        // there are elements in the right side of maxV
        if (maxIndex < (nums.size()-1)) {
            vector<int> rightVec(nums.begin()+maxIndex+1, nums.end());
            node->right = constructMaxBinaryTree(rightVec);
        }
        return node;
    }

    TreeNode* traversal(vector<int>& nums, int start, int end) {
        // the range: [start, end)
        if (start >= end) return nullptr; // the condition to stop
        // find the max
        int maxIndex = start;
        for(int i = start+1; i < end; i++) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxIndex]);
        // left side
        root->left = traversal(nums, start, maxIndex);
        // right side
        root->right = traversal(nums, maxIndex+1, end);
        return root;
    }
    TreeNode* constructBetterMax(vector<int>& nums) {
        // the above code is clear in its logic, but not optimized
        // every time the code create a new vector for either left or right
        // but we do not have to do this
        // note the range here [0, nums.size()), left closed, right open
        //
        return traversal(nums, 0, nums.size());
    }
};

int main() {
    
    return 0;
}

