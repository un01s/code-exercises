/*
 * leetcode 95 unique binary search trees II
 *
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int start, int end){
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(nullptr);
        } else {
            for(int i = start; i <= end; i++) {
                vector<TreeNode*> left_trees = generateTrees(start, i-1);
                vector<TreeNode*> right_trees = generateTrees(i+1,end);
                for(TreeNode *left:left_trees)
                    for(TreeNode *right: right_trees){
                        TreeNode * root = new TreeNode(i);
                        root->left = left;
                        root->right = right;
                        res.push_back(root);
                    }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>();

        return generateTrees(1, n);    
    }
};

