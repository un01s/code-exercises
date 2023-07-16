/*
 * leetcode 257
 * all paths of a binary tree
 * 
 * 2023-7-16
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if(root == nullptr) return result;
        traversal(root, path, result);
        return result;
    }
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
        path.push_back(cur->val);
        // check the leaf node
        if (cur->left == nullptr && cur->right == nullptr) {
            string sPath;
            for(int i = 0; i < path.size()-1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size()-1]);
            result.push_back(sPath);
            return;
        }
        if (cur->left) {
            traversal(cur->left, path, result);
            path.pop_back();
        }
        if (cur->right) {
            traversal(cur->right, path, result);
            path.pop_back();
        }
    }
};

int main() {
    Solution s;

    return 0;
}
