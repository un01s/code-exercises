/*
 * leetcode 226
 *
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        swap(root->left, root->right);  // mid
        invertTree(root->left);         // left
        invertTree(root->right);        // right
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();              // mid
            st.pop();
            swap(node->left, node->right);
            if(node->right) st.push(node->right);   // right
            if(node->left) st.push(node->left);     // left
        }
        return root;
    }
};
