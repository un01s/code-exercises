/*
 * leetcode 217
 * contains duplicate
 *
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }    
        for (auto &p: mp) {
            if (p.second > 1) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num: nums) {
            if (mp.count(num) > 0) return true;
            mp[num]++;
        }
        return false;
    }
};

