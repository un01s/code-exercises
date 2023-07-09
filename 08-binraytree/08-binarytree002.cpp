/**
 * Leetcode 
 * 106 construct binary tree from inorder and postorder traversal
 *
 * Given two integer arrays inorder and postorder where inorder is the inorder 
 * traversal of a binary tree and postorder is the postorder traversal of the 
 * same tree, construct and return the binary tree. 
 *
 * 2023-07-09
 *
 */

#include <iostream>
#include <vector>

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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0) return nullptr;

        // the last element of postorder array is the root
        int rootVal = postorder[postorder.size()-1];      
        TreeNode* root = new TreeNode(rootVal);
        // done, only one node = root node
        if (postorder.size() == 1) return root;

        // find the delimiter for inorder
        int i = 0;
        for(i = 0; i < inorder.size(); i++) {
            if(inorder[i] == rootVal) break;
        } 

        // break the inorder array
        // inorder [0, delimiter)
        vector<int> leftInorder(inorder.begin(), inorder.begin()+i);
        // inorder [delimiter+1, end)
        vector<int> rightInorder(inorder.begin()+i+1, inorder.end());

        // we know that both inorder and postorder array have the same size
        // postorder, remove the last one
        postorder.resize(postorder.size()-1);
        // [0, leftInorder.size())
        vector<int> leftPostorder(postorder.begin(), postorder.begin()+leftInorder.size());
        // [leftInorder.size(), end);
        vector<int> rightPostorder(postorder.begin()+leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root; 
    }   

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) {
            return nullptr;
        }
        return traversal(inorder, postorder);
    }
};

int main() {
    int inorder[] = {9,3,15,20,7};    
    int postorder[] = {9,15,7,20,3};
    
    return 0;
}

