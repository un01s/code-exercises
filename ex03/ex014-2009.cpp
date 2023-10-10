/*
 * leetcode 2009
 *
 * DP
 *
 */

class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int res = 1e9, cur = 0, n = nums.size();
        unordered_map<int, int> cnts;
        
        for(int i = 0, j = 0; i < n; ++i) {
            while(j < n && nums[j] - nums[i] <= n-1) 
                if(++cnts[nums[j++]] == 1) ++cur;
            res = min(res, n - cur);
            if(--cnts[nums[i]] == 0) --cur;
        }
        
        return res;
    }
};
