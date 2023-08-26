# Data Structures and Algorithms

## basics

The fundamental structures are ```array``` and ```linked list```. The basic operations on any data structure are as follows: 
 
| Operation | Array | Linked List |
| -- | ----- | ----------- |
| READ: access to one element | index | Traverse |
| WRITE: modify one element | index | Traverse |
| SEARCH: look for one specific element | index | Traverse |
| ADD: add one new element | resize | pointer |
| MINUS: remove one existing element | move | pointer |

After both ```array``` and ```linked list```, ```string```, ```stack``` and ```queue``` are natural variants of ```array```. Then ```binary tree``` expands ```linked list```. 

```C++
struct ListNode {
    int val;
    ListNode *next;

    // constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traverse(TreeNode* root) {
    // pre-order
    traverse(root->left);
    // in-order
    traverse(root->right);
    // post-order
}
```

### iterative vs. recursive

Programming languages provide many fundamental data types and ways to construct more complex types from them. This is the basis of data structures to solve problems. When traversing a linear data structure such as array, or a singly linked list, it is natural to iterate through it. Both ```for``` and ```while``` loops are there together with other flow control constructs.

```C++
/*
 * iterate through an array
 */
void traverse(vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

struct ListNode {
    int val;
    ListNode* next;
    // constructor
    ListNode(int x) : val(x), next(nullptr) {}
};

/*
 * iterate through a linked list
 */
void traverse(ListNode* head) {
    ListNode* p = head;
    for (; p != nullptr; p = p->next) {
        cout << p->val;
    }
}

/*
 * recurse over a linked list
 */
void traverse(ListNode* head) {
    if (head == nullptr) return;

    cout << head->val << endl;
    traverse(head->next);
}

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
 * recurse through a binary tree
 */
void traverse(TreeNode* root) {
    if (root == nullptr) return;
    
    cout << root->val << endl;
    traverse(root->left);
    traverse(root->right);
}
```

### enumerate every case: no more, no less

DP, Union Find, Greedy, Knapsack, and so on.


