/*
 * leetcode 106
 * construct binary tree from inorder and postorder traversal
 *
 * Given two integer arrays preorder and inorder where preorder is the preorder
 * traversal of a binary tree and inorder is the inorder traversal of the same 
 * tree, construct and return the binary tree.
 *  
 * 
 */

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
    TreeNode* traverse(vector<int>& inorder, vector<int>& postorder) {
        int pSize = postorder.size();
        if (pSize == 0) return nullptr;

        // the last element of postorder array is current mid node
        int rootValue = postorder[pSize-1];
        TreeNode* root = new TreeNode(rootValue);

        // leaf node
        if (pSize == 1) return root; 

        // find where to cut inorder array
        int inIndex;
        for (inIndex = 0; inIndex < inorder.size(); inIndex) {
            if (inorder[inIndex] == rootValue) break;
        }
        // find the root in the inorder array
        // then its left side is the left subtree
        // and its right side is the right subtree
        // use [0, inIndex) and [inIdex+1, inorder.size())
        vector<int> leftInorder(inorder.begin(), inorder.begin()+inIndex);
        vector<int> rightInorder(inorder.begin()+inIndex+1, inorder.end());

        // resize postorder by removing its last element
        postorder.resize(pSize-1);
        
        // cut the postorder array now
        vector<int> leftPost(postorder.begin(), postorder.begin()+leftInorder.size());
        vector<int> rightPost(postorder.begin()+leftInorder.size(), postorder.end());

        // recursive
        root->left = traverse(leftInorder, leftPost);
        root->right = traverse(rightInorder, rightPost);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traverse(inorder, postorder);
    }
};

