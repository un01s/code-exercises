/*
 * leetcode 2441
 * largest positive integer that exists with its negative
 */

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        uint8_t seen[1001] = {0};
        int k = -1;
        for (int x : nums) {
            if (x < 0) {
                x = -x;
                seen[x] |= 2;
            } else
                seen[x] |= 1;
            if (seen[x] == 3 && x > k)
                k = x;
        }
        return k;
    }
};

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n - 1;
        sort(nums.begin(), nums.end());
        while (l < r && nums[l] != -nums[r]) {
            if (-nums[l] > nums[r])
                l++;
            else
                r--;
        }
        return (l < r) ? nums[r] : -1;
    }
};

