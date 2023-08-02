/*
 * leetcode 337
 * tree
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
    int rob(TreeNode* root) {
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    }
    vector<int> robTree(TreeNode* cur) {
        if (cur == nullptr) return vector<int>(2, 0); // two zeros
        
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        // if rob cur, then no left and right sub
        int val1 = cur->val + left[0] + right[0];
        // not rob cur, then left and right sub
        int val2 = max(left[0], left[1] + max(right[0], right[1]));
        vector<int> res;
        res.push_back(val1);
        res.push_back(val2);
        return res;
    }
};

int main() {
    return 0;
}
