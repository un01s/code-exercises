/**
 * Leetcode 501 
 *
 * most frequent values of the BST
 *
 * BST is an ordered binary tree
 * if its left sub-tree is not empty, all node values are less than its root value
 * if its right sub-tree is not empty, all node values are greater than its root value
 *
 * use the inorder traveral, the output array should be ordered
 * then check the array to find out the minimum abs difference!
 *
 * 2023-07-18
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
    void print(vector<int>& v) {
        cout << ":";
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << " "; 
        }
        cout << endl;
    }

    vector<int> result;
    TreeNode* pre;
    int count = 0;
    int maxCount = 0;

    // inorder 
    void searchBST(TreeNode* cur) {
        if (cur == nullptr) return; // termination condition

        searchBST(cur->left); // left

        // process the node
        if (pre == nullptr) {
            count = 1; // first
        } else if (pre->val == cur->val) {
            count++;
        } else { // different from the last one
            count = 1;
        }
        pre = cur;

        if (count == maxCount) {
            maxCount = count;
            result.push_back(cur->val);
        }
        if (count > maxCount) {
            maxCount = count;
            result.clear(); // clear the before
            result.push_back(cur->val);
        }

        searchBST(cur->right); // right
        return;
    }

    vector<int> findMode(TreeNode* root) {
        count = 0;
        maxCount = 0;
        TreeNode* pre = nullptr;
        result.clear();

        searchBST(root);
        return result;
    }
};

int main() {
    
    return 0;
}

