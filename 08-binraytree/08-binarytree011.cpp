/**
 * Leetcode 513 
 *
 * last line, leftest leaf
 * it may not be a left-leaf, but the leftest leaf at the max depth
 *
 * traverse and back-tracking
 *
 * 2023-07-16
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
    int maxDepth = 0;
    int result;
    void traversal(TreeNode* root, int depth) {
        if (root->left == nullptr && root->right == nullptr) {
            if (depth > maxDepth) {
                maxDepth = depth;
                result = root->val; // leaf value
            }
            return;
        }
        if (root->left) {
            //depth++;
            //traversal(root->left, depth);
            //depth--; // back tracking
            traversal(root->left, depth+1);
        }
        if (root->right) {
            //depth++;
            //traversal(root->right, depth);
            //depth--; // back tracking
            traversal(root->right, depth+1);
        }
        return; 
    }
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0); 
        return result;
    }
};

int main() {
    
    return 0;
}

