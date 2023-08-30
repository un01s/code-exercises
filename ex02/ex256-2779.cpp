/*
 * leetcode 2779
 *
 */

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int startIndex = -1, endIndex = 0, n = nums.size(), res = 0;
        int startInterval = -1e7, endInterval = -1e7;
        for(endIndex = 0; endIndex < n; endIndex += 1) {
            while(nums[endIndex] - k > endInterval) {
                startIndex += 1;
                startInterval = nums[startIndex] - k, endInterval = nums[startIndex] + k;
            }
            res = max(res, endIndex - startIndex + 1);
        }
        return res;        
    }
};
