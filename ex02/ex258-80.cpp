/*
 * leetcode 80
 * remove duplicates from sorted array II
 *
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int k = 1;
        for (int i = 2; i < n; i++) {
            int now = nums[i];
            if (now == nums[k] && now == nums[k-1]) continue;
            nums[++k] = now;
        }
        return k+1;
    }
};

