/*
 * leetcode 742
 * closest leaf in a binary tree
 *
 * https://github.com/grandyang/leetcode/issues/742
 *
 * binary tree, every node has a unique value
 * give a target value, k, find the value of its nearest leaf node
 *
 * 2023-07-19
 *
 * a binary tree can be stored in linked lists or an array.
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* convertArray(vector<int>& nums) {
    TreeNode* root = new TreeNode(nums[0]);
    for(int i = 1; i < nums.size(); i++) {
        if (nums[i] != -1) {
            
        }
    }
    return root;
}

class Solution {
public:
    void helper(TreeNode* node, int cur, unordered_map<int, int>& m, int& mn, int& res) {
        if (node == nullptr) return;
        if (m.count(node->val)) cur = m[node->val];
        if (node->left == nullptr && node->right == nullptr) {
            if (mn > cur) {
                mn = cur;
                res = node->val;
            }
        }
        helper(node->left, cur+1, m, mn, res);
        helper(node->right, cur+1, m, mn, res);
    }
    int find(TreeNode* node, int k, unordered_map<int, int>& m) {
        if (node == nullptr) return -1;
        if (node->val == k) return 1;
        int r = find(node->left, k, m);
        if (r != -1) {
            m[node->val] = r;
            return r+1;
        }
        r = find(node->right, k, m);
        if (r != -1) {
            m[node->val] = r;
            return r+1;
        }
        return -1;
    }
    int findClosestLeaf(TreeNode* root, int k) {
        int res = -1; 
        int mn = INT_MAX;
        unordered_map<int, int> mp;
        mp[k] = 0;

        find(root, k, mp);
        helper(root, -1, mp, mn, res);

        return res;
    }
};

int main() {
    int a[] = {1, 3, 2};
    vector<int> v1(a, a + sizeof(a)/sizeof(int)); 
    int k1 = 1;
    int a1 = 2; // or 3

    Solution s;
    TreeNode* t1 = convertArray(v1);
    if (2 == s.findClosestLeaf(t1, k1) || 3 == s.findClosestLeaf(t1, k1)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    return 0;
}

