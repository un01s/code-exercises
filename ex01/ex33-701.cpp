/**
 * Leetcode 701 
 *
 * insert into a binary search tree
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

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // if the root is empty
        TreeNode* node = new TreeNode(0);
        if (root == nullptr) {
            node->val = val;
            root = node;
        }
        // the root is not empty
        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        }
        if (root->val < val) {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

int main() {
    
    return 0;
}

