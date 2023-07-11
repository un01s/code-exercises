/*
 * leetcode 145 binary tree post-order traversal
 * 
 *
 * TODO
 * the first solution is using the doubly linked list and unordered_map
 *
 * the second has the map with a doubly linked list, and another deque!
 * the unordered_map is better than the map used.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

// doubly linked list node
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (cur == NULL) return;
        traversal(cur->left, vec);  // left
        traversal(cur->right, vec); // right
        vec.push_back(cur->val);    // root (mid)
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

int main() {

    return 0;
}
