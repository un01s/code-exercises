# basic data structures

* array
* linked list
* list
* stack
* queue
* hash table
* heap
* graph

## operations on an array

### traverse

```C++
void traverse(vector<int>& nums) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        count++;
    }
}
```

### find

```C++
// -1 not found, or the index in the array returned
int find(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}
```

## operations on a linked list

### signly linked list

```C++
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

// insert q after p
void insert(ListNode* p, ListNode* q) {
    ListNode* t = p->next;
    q->next = t;
    p->next = q;
}

// remove the first node after n
int find(ListNode* head, int target) {
    int index = 0;
    while(head != nullptr) {
        if (head->val == target) return index;
        head = head->next;
        index++;
    }
    return -1;    
}
```

### doubly linked list

```C++
struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode(int x): val(x), next(nullptr), prev(nullptr) {}
};

```

