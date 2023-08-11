/*
 * leetcode 2799
 * 2799. Count Complete Subarrays in an Array
 */

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }
        int d = m.size();
        m.clear();

        int c = 0;
        for(int i = 0; i < n; i++) {
            m[nums[i]]++;
            for(int j = i; j< n; j++) {
                m[nums[j]]++;
                if (m.size()==d) {
                    c++;
                }
            }
            m.clear();
        }        
        return c;
    }
};
