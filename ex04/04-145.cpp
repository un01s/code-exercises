/*
 * leetcode 145
 * binary tree postorder traversal
 *
 */

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int>res;
        stack<TreeNode*>st;
        unordered_set<TreeNode*>Set;
        
        while (!st.empty() || root!=nullptr)
        {
            if (root!=nullptr)
            {
                st.push(root);
                root=root->left;
            }
            else
            {
                root=st.top();
                if (Set.find(root)==Set.end())
                {
                    Set.insert(root);
                    root = root->right;
                }
                else
                {
                    res.push_back(root->val);
                    st.pop();
                    root=nullptr;
                }
            }
        }
        
        return res;
    }
};
