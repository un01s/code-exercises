/**
 * Leetcode 113 
 *
 * find all the paths whose sum is equal to a target.
 *
 * 2023-07-17
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
    vector<vector<int> > result;
    vector<int> path;

    void traverse(TreeNode* cur, int count) {
        // use minus instead of addition
        // at the end both count == 0 and the node is a leaf
        if (!cur->left && !cur->right && count == 0) {
            result.push_back(path);
            return;
        }
        // it is a leaf but count != 0
        if (!cur->left && !cur->right) return;
 
        // continue to left
        if (cur->left) {
            path.push_back(cur->left->val);
            count -= cur->left->val;
            // recursive
            traverse(cur->left, count);
            count += cur->left->val;
            path.pop_back();
        }
        // countinue to right 
        if (cur->right) {
            path.push_back(cur->right->val);
            count -= cur->right->val;
            // recursive
            traverse(cur->right, count);
            count += cur->right->val;
            path.pop_back();
        }
        return;
    }
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        result.clear();
        path.clear();
        if (root == nullptr) return result;
        path.push_back(root->val);
        traverse(root, sum - root->val);
        return result;
    }    
};

int main() {
    
    return 0;
}

