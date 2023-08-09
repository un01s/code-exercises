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

