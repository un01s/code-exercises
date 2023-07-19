/**
 * Leetcode 236 
 *
 * lowest common ancestor of two nodes on a binary tree
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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // when to stop
        if (root == p || root == q || root == nullptr) return root;
        // what to do
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != nullptr && right != nullptr) return root;

        if(left == nullptr && right != nullptr) return right;
        else if (left != nullptr && right == nullptr) return left;
        else {  return nullptr; }
    }
};

int main() {
    
    return 0;
}

