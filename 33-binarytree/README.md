# binary tree

## traversal of a binary tree, a vector, a linked list

### traverse a binary tree

```C++
void traverse(TreeNode* root) {
    if (root == nullptr) return;

    // pre-order
    traverse(root->left);
    // inorder
    traverse(root->right);
    // postorder
}
```

### traverse an array iteratively and recursively

```C++
void traverse(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        // traverse an array iteratively
    }
}
```

```C++
void traverse(vector<int>& nums, int i) {
    if (i == nums.size()) return;

    // preorder
    traverse(nums, i+1);
    // postorder
}
```

### traverse a linked list

```C++
void traverse(ListNode* head) {
    for (ListNode* p = head; p != nullptr; p = p->next) {
        // iteratively
    }
    // or with while loop
    while(head != nullptr) {
        // iteratively
        head = head->next;
        // processing
    }
}
```

```C++
void traverse(ListNode* head) {
    if (head != nullptr) return;

    // preorder
    traverse(head->next);
    // postorder
}
```

## DP, DFS, and Backtracking as binary tree extension

* Dynamic Programming is divid and conquer. Its focus is on one subtree.

### count the number of nodes in a binary tree

```C++
int count(TreeNode* root) {
    if (root == nullptr) return 0;

    int leftCount = count(root->left);
    int rightCount = count(root->right);

    return leftCount+rightCount+1;
}
```

```C++
int fib(int n) {
    if (n==1 || n==2) return 1;
    return fib(n-1)+fib(n-2);
}
```

* Backtracking is traversing. Its focus is on the branch between two nodes.

```C++
void traverse(TreeNode* root) {
    if (root == nullptr) return;

    // from root to root->left
    traverse(root->left);
    // back
    // from root to root->right
    traverse(root->right);
    // back
}

void backtrack(...) {
    for(int i = 0; i < ...; i++) {
        // select
        ...
        // next level
        backtrack(...);
        // undo the previous selection
        ...
    }
}
```

* DFS is also traversing. Its focus is on a single node.

```C++
void traverse(TreeNode* root) {
    if (root == nullptr) return;

    root->val++;
    traverse(root->left);
    traverse(root->right);
}
```
