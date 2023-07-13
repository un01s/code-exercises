/**
 * Leetcode 102 level traversal of a binary tree 
 *
 *  3
 * / \
 * 9 20
 *   / \
 *  15  7
 * 
 * [3 9 20 null null 15 7]
 *
 * output:
 * [[3], [9, 20], [15, 7]]
 *
 * 2023-07-13
 *
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
    vector<vector<int> > levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        vector<vector<int> > result; // each level is a vector
        while(!que.empty()) {
            int size = que.size();
            vector<int> v;
            for(int i = 0; i < size; i++) {
                TreeNode* n = que.front();
                que.pop();
                v.push_back(n->val);
                if (n->left) que.push(n->left);
                if (n->right) que.push(n->right);
            }
            result.push_back(v);
        }
        return result;
    }
};

// recursive
class Solution2 {
public:
    void order(TreeNode* cur, vector<vector<int> >& result, int depth) {
        if (cur == nullptr) return;
        if (result.size() == depth) result.push_back(vector<int>());
        result[depth].push_back(cur->val);
        order(cur->left, result, depth+1);
        order(cur->right, result, depth+1);
    }
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        int depth = 0;
        order(root, result, depth);
        return result;
    }
};

int main() {
    
    return 0;
}

