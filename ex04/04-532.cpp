/*
 * leetcode 532
 * 
 * double-pointer
 *
 * sorting first
 * for every i, move j to check if nums[i]+k == nums[j]
 * make sure i skipping the duplicates
 * for every i, make sure j = i+1
 *
 */

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return 0;
        
        sort(nums.begin(),nums.end());
        
        int i = 0;
        int j = 1;
        int count = 0;
        
        while (j < n) {
            j = i+1;
            while (j < n && nums[j] < nums[i]+k) j++;
            if (j < n && nums[j] == nums[i]+k)
                count++;
            i++;
            while (i < n && nums[i] == nums[i-1]) i++;
        }
        
        return count;
    }
};

