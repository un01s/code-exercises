/**
 * Leetcode 617 
 *
 * merge two binary tree
 * 
 * if overlapped, the sum of their values as new value
 * the null node will be the node 
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

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // when to stop
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;
        // what to do now, when both trees are not empty
        // inorder traversal
        t1->val += t2->val; // mid + mid
        t1->left = mergeTrees(t1->left, t2->left); // left + left
        t1->right = mergeTrees(t1->right, t2->right); // right + right
        // return
        return t1;
    }
};

int main() {
    
    return 0;
}

