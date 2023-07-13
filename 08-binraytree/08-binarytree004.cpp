/**
 * Leetcode 226 
 *
 *  3
 * / \
 * 9 20
 *   / \
 *  15  7
 * 
 *    3
 *   / \
 *  20  9
 * / \
 * 7 15
 *
 * 2023-07-13
 *
 * just swap left and right child-node
 *
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// recursive
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) retur root; // terminate
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

// iterative
class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        stack<TreeNode*> st; // stack, LIFO
        st.push(root); // mid
        while(!st.empty()) {
            TreeNode* n = st.top(); // mid
            st.pop();
            swap(n->left, n->right);
            if (n->right) st.push(n->right); // right
            if (n->left) st.push(n->left); // left
        }
        return root;
    }
};

int main() {
    return 0;
}
