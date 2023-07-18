/**
 * Leetcode 700 
 *
 * binary search tree
 *
 * BST is an ordered binary tree
 * if its left sub-tree is not empty, all node values are less than its root value
 * if its right sub-tree is not empty, all node values are greater than its root value
 *
 * if overlapped, the sum of their values as new value
 * the null node will be the node 
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

    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr || root->val == val) return root;
        // what to do now
        TreeNode* result = nullptr;
        if (root->val > val) {
            result = searchBST(root->left, val);
        } 
        if (root->val < val) {
            result = searchBST(root->right, val);
        }
        return result;
    }
    // a little concise
    TreeNode* bst(TreeNode* root, int val) {
        if (root == nullptr || val == root->val) return root;
        if (root->val > val) return bst(root->left, val);
        if (root->val < val) return bst(root->right, val);
        return nullptr;
    }
};

int main() {
    
    return 0;
}

