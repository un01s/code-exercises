/*
 * https://leetcode.com/contest/weekly-contest-361/ranking/1/
 *
 */
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        for(auto &c : nums) {
            c = (c % modulo == k) ? 1 : 0;
        }
        int prefix = 0;
        map<int, int> frec;
        frec[0] = 1;
        long long res = 0;
        for(int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            if(prefix >= modulo) prefix -= modulo;
            int cur = (prefix - k + modulo) % modulo;
            res += frec.count(cur) ? frec[cur] : 0;
            frec[prefix] += 1;
        }
        return res;    
    }
};
