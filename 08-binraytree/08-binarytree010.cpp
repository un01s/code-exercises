/**
 * Leetcode 257 binary tree paths
 *
 *
 * 2023-07-15
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
    void traverse(TreeNode* cur, vector<int>& path, vector<string>& result) {
        path.push_back(cur->val);
        // the condition to stop recursion
        if (cur->left == nullptr && cur->right == nullptr) {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            // last path
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }
        // recursion + back tracking
        if (cur->left) {
            traverse(cur->left, path, result);
            path.pop_back(); // back tracking
        }
        if (cur->right) {
            traverse(cur->right, path, result);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if (root != nullptr) {
            traverse(root, path, result);
        }
        return result;    
    }
};

int main() {
    
    return 0;
}

