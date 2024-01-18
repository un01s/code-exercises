/*
 * leetcode 3005
 *
 * 1 <= nums.size() <= 100
 * 1 <= nums[i] <= 100
 *
 * use map to count the frequency of each element
 * then find out the max frequency
 * then add the max frequency
 *
 */

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mp;

        for (auto x : nums) ++mp[x];

        int mx = 0;
        for (auto [x, y] : mp) mx = max(mx, y);

        int res = 0;
        for (auto [x, y] : mp) if (mx == y) res += y;
        return res;
    }
};


