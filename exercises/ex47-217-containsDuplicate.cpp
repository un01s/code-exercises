/*
 * leetcode 217 
 * contains duplicate
 *
 * use the unordered_map is so neat!
 * by default, the unordered_map is initialized to zeros.
 *
 * the second solution uses unordered_set
 * it uses the array to initialize the set
 * then compare the size of the array with the size of set.
 *
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = m[nums[i]] + 1;
            if (m[nums[i]] > 1) return true;
        }
        return false;
    }
};

// this is another way to use unordered_set
// neat too!

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        return nums_set.size() != nums.size();
    }
};


