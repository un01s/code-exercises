# basic data structures

* array
* linked list
* hash table
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

```C++
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};


```

