/*
 * leetcode 124
 * binary tree maximum path sum
 *
 * A path in a binary tree is a sequence of nodes where each pair of adjacent 
 * nodes in the sequence has an edge connecting them. A node can only appear in  * the sequence at most once. Note that the path does not need to pass through 
 * the root.
 * 
 * The path sum of a path is the sum of the node's values in the path.
 * 
 * Given the root of a binary tree, return the maximum path sum of any non-empty * path.
 * 
 * input: root = [1, 2, 3]
 * output: 6
 * the path is from 2->1->3. 1 is the root. 2 is the left leaf and 3 the right.
 *
 * input: root = [-10, 9, 20, null, null, 15, 7]
 * output: 42
 * the path 15->20->7
 *
 *
 * binary tree, dfs, recursive
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
    int res = INT_MIN;
    // this is actually a post-order traversal of a binary tree:
    //
    // go to left sub-tree, then 
    // go to right sub-tree
    // go to the root node at last
    // 
    // the only thing tricky is that the traversal and the computation is
    // bit different. 
    //  
    int dfs(TreeNode* cur) {
        if (cur == nullptr) return 0; // empty
        // recursively
        int left = max(0, dfs(cur->left));
        int right = max(0, dfs(cur->right));
        // computation has to be a path!
        // with split from the current node
        // the path is from left-sub -> cur -> right-sub
        res = max(res, left+right+cur->val);

        // with no split from the current node
        // either left or right
        // if split here, then this segment cannot be used as a part of a path
        // return the value from one side only, this is to ensure it can be
        // used as a segment of a path.
        // choose the max
        return max(left, right)+cur->val;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};

int main() {
    return 0;
}
