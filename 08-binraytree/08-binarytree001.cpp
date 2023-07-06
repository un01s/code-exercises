/**
 * Leetcode 144 binary pre-order traversal 
 *
 * Given the root of a binary tree, return the preorder traversal of 
 * its nodes' values.
 * 
 * 2023-07-03
 *
 * Leetcode: 
 * 94: binary tree in-order traversal
 * 255: verify preorder sequence in binary search tree
 * 589: N-ary tree preorder traversal
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
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    } 
};

int main() {
    
    return 0;
}

