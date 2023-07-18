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
};

int main() {
    
    return 0;
}

