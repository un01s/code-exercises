/*
 * leetcode 145
 *
 */

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            // empty node not pushed to the stack
            if (node->left) st.push(node->left); 
            if (node->right) st.push(node->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
