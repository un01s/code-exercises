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
 */

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
    Node* connect(Node* root) {
        
    }
};


