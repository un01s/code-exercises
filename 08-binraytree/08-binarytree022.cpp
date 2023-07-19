/**
 * Leetcode 235 
 *
 * lowest common ancestor of a binary search tree
 *
 *
 * 2023-07-19
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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* traversal(TreeNode* cur, TreeNode* p, TreeNode* q) {
        if (cur == nullptr) return cur;

        if (cur->val > p->val && cur->val > q->val) {
            TreeNode* left = traversal(cur->left, p, q);
            if (left != nullptr) {
                return left;
            }
        }

        if (cur->val < p->val && cur->val < q->val) {
            TreeNode* right = traversal(cur->right, p, q);
            if (right != nullptr) {
                return right;
            }
        }

        return cur;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traversal(root, p, q);            
    }
};

int main() {
    return 0;
}
