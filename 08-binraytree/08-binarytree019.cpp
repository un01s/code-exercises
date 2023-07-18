/**
 * Leetcode 530 
 *
 * min absolute difference in BST
 *
 * BST is an ordered binary tree
 * if its left sub-tree is not empty, all node values are less than its root value
 * if its right sub-tree is not empty, all node values are greater than its root value
 *
 * use the inorder traveral, the output array should be ordered
 * then check the array to find out the minimum abs difference!
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
    int getMinimumDiff(TreeNode* root) {
        v.clear();
        traversal(root);
        if (v.size() < 2) return 0;
        int r = INT_MAX;
        for (int i = 1; i < v.size(); i++) {
            r = min(r, v[i]-v[i-1]);
        }
        return r;
    }

    // another solution
    int result = INT_MAX;
    TreeNode* pre = nullptr;
    void traverse(TreeNode* cur) {
        if (cur == nullptr) return;
        traverse(cur->left);
        if (pre != nullptr) {
            result = min(result, cur->val-pre->val);
        }
        pre = cur; // record this pointer
        traverse(cur->right);
    }
    // check the min difference during the traversal
    int getMinDiff(TreeNode* root) {
        traverse(root);
        return result;
    }
};

int main() {
    
    return 0;
}

