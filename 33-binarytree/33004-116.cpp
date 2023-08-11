/*
 * leetcode 116
 * populating next right pointers in each node
 *
 * perfect binary tree: 
 * - all leaves are on the same level and 
 * - every parent has two children
 * 
 * input: root = [1, 2, 3, 4, 5, 6, 7]
 * output: [1, null, 2, 3, null, 4, 5, 6, 7, null]
 *
 * imagine this not as a binary tree, because we are going to connect
 * the gaps between two nodes at the same level (this is perfect binary tree)
 * 
 *     1
 *    / \
 *   2   3
 *  / \ / \
 * 4  5 6  7
 * 
 * 
 * ===============================
 * JUST use the second solution!!!
 * ===============================
 *
 */

#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    void traverse(Node* left, Node* right) {
       //
       if (left == nullptr || right == nullptr) {
           return;
       }
       // preorder: mid

       left->next = right;
       // connect two children with the same parent node
       traverse(left->left, left->right);
       traverse(right->left, right->right);
       // connect two neighboring nodes with different parent node
       traverse(left->right, right->left);
    }
    Node* connect(Node* root) {
        if (root == nullptr) return root;

        traverse(root->left, root->right);
        return root;    
    }
};

// time O(n)
// space O(n)
class Solution2 {
public:
    Node* connect(Node* root) {
        if (root==NULL) return NULL;

        if (root->left) root->left->next = root->right;
        if (root->right && root ->next) root->right->next = root->next->left;

        connect(root->left);
        connect(root->right);

        return root;
    }
};

int main() {
    return 0;
}
