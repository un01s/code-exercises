# linear data structures

Array, linked list, stack and queue are all linear data structures. Each element in these structures has a linear logical relationship to each other. However, the storage of these elements might be either linear like array or scattered like linked list. Each element in these linear structures should be the same data type.

## array

### [leetcode 27 remove element in-place](https://leetcode.com/problems/remove-element/)

```C++
class Solution {
public:
    // remove all occurances of val in nums
    // return the number of elements that are not equal to val
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
    // double-pointer: 
    // k is the left pointer, i the right pointer
    // both pointers move in the same direction
};
```

### [leetcode 35 search insert position](https://leetcode.com/problems/search-insert-position/)

```
class Solution {
public:
    // recursive
    // binary search for a sorted array
    int bSearch(vector<int>& nums, int target, int start, int end) {
        int mid = (start + end) / 2;
            if(target > nums[nums.size() - 1]) return nums.size();

 	    if(mid == start || mid == end){
 		if(target > nums[start]) return end;
 		else return start;
 	    }
 	    if(nums[mid] == target) return mid;
 	    else if(nums[mid] > target) return bSearch(nums, target, start, mid);
 	    else return bSearch(nums, target, mid, end);
    }
    // return the index if the target is found
    // if not, return the index where it would be inserted in order
    //
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) {
            if (target > nums[0]) {
                return 1;
            } else {
                return 0;
            }
        }
        return bSearch(nums, target, 0, nums.size()-1);
    }
};
```

