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
};
```


