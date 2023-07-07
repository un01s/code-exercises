#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class BinaryTree {
private:
    TreeNode* root;
    void insert(TreeNode* n, int val) {
        if(!n) return;
        //check which side the value should go
        if(n->val >= val) {
            // left for lower
            if(!n->left) {
                n->left = create(val);
            } else {
                insert(n->left, val);
            }
        } else {
            // right for higher
            if(!n->right) {
                n->right = create(val);
            } else {
                insert(n->right, val);
            }
        }
    }

    TreeNode* create(int val) {
        TreeNode* n = new TreeNode;
        n->val = val;
        n->left = nullptr;
        n->right = nullptr;

        return n;
    }

    void printTree(TreeNode* n) {
        if(n) {
            printTree(n->left);
            cout << " " << n->val << " ";
            printTree(n->right);
        }
    }

public:
    BinaryTree(int val) {
        root = create(val);
    }
    void addItem(int val) {
        insert(root, val);
    }
    void print() {
        printTree(root);
        cout << endl;
    }
};

int main() {

    BinaryTree tree = BinaryTree(5);
    tree.addItem(3);
    tree.addItem(7);
    tree.print();
    
    return 0;
}
