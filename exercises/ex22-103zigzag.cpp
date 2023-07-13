/*
 * leetcode 103 binary tree zigzag level order traversal
 * 
 * level: from root to leaf and from left to right
 *
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

// now it is correct!
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > r;
        int order = 0;
        queue<TreeNode*> q;
        if (root != nullptr) q.push(root);
        while(!q.empty()) {
            vector<int> v; // result for one-level
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* n = q.front();
                q.pop();
                if (order%2 == 0) {
                    v.push_back(n->val);
                } else {
                    v.insert(v.begin(), n->val);
                }
                cout << "Order=" << order << ":"; 
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            order++;
            for (int j = 0; j < s; j++) {
                cout << v[j] << " ";
            }
            cout << endl;
            r.push_back(v);
        }
        return r;
    }
};

int main() {
    return 0;
}
