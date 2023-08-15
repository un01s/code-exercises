/*
 * build a binary tree
 * from a level-traversed tree
 *
 * leetcode 102 binary tree level order traversal
 * leetcode 107 binary tree level order traversal II
 *
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth)+1;    
    }
    int nodeCount(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = nodeCount(root->left);
        int right = nodeCount(root->right);
        return left+right+1; // total number of nodes in a binary tree
    }
};

//
// DFS traversal always focuses on the node
//
void dfs(TreeNode* root) {
    if (root == nullptr) return;
    // enter root
    cout << ":enter root = " << root->val << endl;
    dfs(root->left);
    dfs(root->right);
    // leave root
    cout << ":leave root = " << root->val << endl;
}

//
// backtracking always focuses on the braches
// then dynamic programming is always on the sub-tree
//
void backtrack(TreeNode* root) {
    if (root == nullptr) return;
    // traverse all child nodes
        // here the child in the case of binary tree
        // there are only left and right child
        backtrack(root->left);
        backtrack(root->right);
    //
}

// how to use an array of level traversal to build a binary tree
// -1 is special as null node
//
TreeNode* buildBinaryTree(vector<int>& nums) {
    // level traverse
    if (nums[0] != -1) {
        TreeNode* head = new TreeNode(nums[0]);
        return head;
    }
    int n = nums.size();
    int count = 0;
    // TODO
    return nullptr; 
}

int main() {
    int t1[] = {3, 9, 20, -1, -1, 15, 7};
    vector<int> v1(t1, t1+sizeof(t1)/sizeof(int));

    Solution s;
    if (3 == s.maxDepth(buildBinaryTree(v1))) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    return 0;
}
