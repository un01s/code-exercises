/*
 * leetcode 3005
 * count elements with max frequency
 * 
 */

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101] = {0}, maxF = 0;
        for (int x : nums) {
            freq[x]++;
            maxF = max(maxF, freq[x]);
        }
        int ans = 0;
        for (int f : freq) {
            if (f == maxF)
                ans += f;
        }
        return ans;
    }
};

