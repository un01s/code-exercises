/*
 * leetcode 26
 * array is sorted. use double-pointer: fast and slow
 * in-place
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1;
        while(j < nums.size()) {
            if (nums[j] == nums[j-1]) {
                j++;
            } else {
                i++;
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return i+1;
    }
};

// still double-pointer
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (j == 0) continue;
            else if (nums[j] == nums[i]) continue;
            else {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};


