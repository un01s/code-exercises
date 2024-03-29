/*
 * Leetcode 001 two sum
 * https://www.techinterviewhandbook.org/grind75
 *
 */

// brute force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (nums[i]+nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // no solution found
    }
};

// unordered map: count(x)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int tmp;

        for (int i = 0; i < n; i++) {
            tmp = target - nums[i];
            if (mp.count(tmp)) {
                return {i, mp[tmp]};
            }            
            mp[nums[i]] = i;
        }
        return {};
    }
};

// unordered_map find(x)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            int c = target - nums[i];
            if (m.find(c)!=m.end()) {
                return {m[c], i};
            }
            m[nums[i]] = i;
        }    
        return {};
    }
};


