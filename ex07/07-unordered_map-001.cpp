/*
 * leetcode 1
 * two sum
 *
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            int tmp = target-nums[i];
            if (m.count(tmp)) {
                return {m[tmp], i};
            }
            m[nums[i]] = i;
        }    
        return {};
    }
};

