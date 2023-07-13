/*
 * leetcode 107 level-order traversal of a binary tree II
 * 
 * level: from root to leaf and from left to right
 *
 * requirement: from leaf to root and from left to right
 * 
 * 2023-07-13
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > r, s;
        queue<TreeNode*> q;
        if (root != nullptr) q.push(root);
        while(!q.empty()) {
            int s = q.size();
            vector<int> v;
            for (int i = 0; i < s; i++) {
                TreeNode* n = q.front(); 
                q.pop();
                v.push_back(n->val); // result
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            r.push_back(v);
        }
        // now the result has the order from left to right and top-down
        // need to reverse to bottom to top
        int rs = r.size();
        for (int i = 0; i < rs; i++) {
            s.push_back(r[rs-i-1]);
        }
        return s;
    }
};

int main() {
    return 0;
}
