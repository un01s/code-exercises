/**
 * Leetcode 538 
 *
 *   
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:

    int pre = 0;
    // this is a reversed inorder traversal
    // right, mid, left
    // so it goes to the right end first
    // and start the addition and accumulation from there.
    void traverse(TreeNode* cur) {
        if (cur == nullptr) return;
        traverse(cur->right); // right
        cur->val += pre;  // mid
        pre = cur->val;
        traverse(cur->left); // left
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        pre = 0;
        traverse(root);
        return root;
    }    
};

int main() {
    
    return 0;
}

