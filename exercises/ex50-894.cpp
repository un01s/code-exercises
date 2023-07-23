/*
 * leetcode 894
 * all possible full binary trees
 * given n, return a list of all possible full binary trees with n nodes.
 * 
 * a full binary tree is a binary tree where each node has 
 * exactly 0 or 2 children.
 * 
 * 2023-07-23
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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> res;
        if (n == 1) {
            res.push_back(new TreeNode(0));
            return res;
        }
        n--;
        for (int i = 1; i < n; i += 2) {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n - i);
            for (int i = 0; i < left.size(); i++) {
                for (int j = 0; j < right.size(); j++) {
                    TreeNode* cur = new TreeNode(0);
                    cur->left = left[i];
                    cur->right = right[j];
                    res.push_back(cur);
                }
            }
        }
        return res;    
    }
};

int main() {
    Solution s;

    return 0;
}
