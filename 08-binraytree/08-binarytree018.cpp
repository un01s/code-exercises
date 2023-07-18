/**
 * Leetcode 98 
 *
 * verify binary search tree
 *
 * BST is an ordered binary tree
 * if its left sub-tree is not empty, all node values are less than its root value
 * if its right sub-tree is not empty, all node values are greater than its root value
 *
 * use the inorder traveral, the output array should be ordered
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

    vector<int> v;
    void traversal(TreeNode* root) {
        if (root == nullptr) return;
        traversal(root->left); // left
        v.push_back(root->val); // mid
        traversal(root->right); // right
    }
    bool isValidBST(TreeNode* root) {
        v.clear();
        traversal(root);
        // i has to start from 1 instead of 0
        for (int i = 1; i < v.size(); i++) {
            if (v[i] <= v[i-1]) return false;
        }
        return true;
    }
};

int main() {
    
    return 0;
}

