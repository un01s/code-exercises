/**
 * Leetcode 106 
 *
 * construct a binary tree according its in-order and post-order traversals
 *
 * inorder [9, 3, 15, 20, 7]
 * postorder [9,15 7, 20, 3]
 * assume that there is no duplicates.
 * the binary tree
 * 
 * inorder: left, mid, right
 * postorder: left, right, mid
 *   3
 *  7 20
 * 9 15
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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return nullptr;
        // last element in postorder is current mid node (root)
        int rootV = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootV);
        // leaf
        if (postorder.size() == 1) return root;
        // find the delimiter in inorder
        int i;
        for (i = 0; i < inorder.size(); i++) {
            if (inorder[i] == rootV) break;
        }
        // cut the inorder into two
        // [0, i) and [i+1, size())
        vector<int> leftInorder(inorder.begin(), inorder.begin()+i);
        vector<int> rightInorder(inorder.begin()+i+1, inorder.end());

        // postorder, remove the last element
        postorder.resize(postorder.size()-1);
        // cut the post order into two
        vector<int> leftPostorder(postorder.begin(), postorder.begin()+leftInorder.size());
        vector<int> rightPostorder(postorder.begin()+leftInorder.size(), postorder.end());

        print(leftInorder);
        print(rightInorder);
        print(leftPostorder);
        print(rightPostorder);

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traversal(inorder, postorder);
    }
};

int main() {
    
    return 0;
}

