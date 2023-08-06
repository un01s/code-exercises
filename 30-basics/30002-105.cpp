/*
 * leetcode 105
 * construct binary tree from preorder and inorder traversal
 *
 * Given two integer arrays preorder and inorder where preorder is the preorder
 * traversal of a binary tree and inorder is the inorder traversal of the same 
 * tree, construct and return the binary tree.
 *  
 * the traverse() function is basically a preorder traversal.
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
    TreeNode* traverse(vector<int>& preorder, int preStart, int preEnd, 
                       vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd) return nullptr;
        if (inStart >= inEnd) return nullptr;

        // preorder: the first is the root
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int index;
        for (index = inStart; index < inEnd; index++) {
            if (inorder[index]==rootVal) {
                break;
            }
        }
        int leftSize = index - inStart;
        
        // recursive: [start, end)
        root->left = traverse(preorder, preStart+1, preStart+leftSize+1,
                              inorder, inStart, index); 
        root->right = traverse(preorder, preStart+leftSize+1, preEnd,
                              inorder, index+1, inEnd); 

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preSize = preorder.size();
        int inSize = inorder.size();

        if (preSize == 0 || inSize == 0) return nullptr;
        return traverse(preorder, 0, preSize, inorder, 0, inSize);        
    }
};

