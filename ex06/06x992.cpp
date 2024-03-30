/*
 * leetcode 992
 * subarrays with k different integers
 * 
 * sliding window
 * similar problems: 713, 2302, 2958, 2962 
 * 
 * 
for(int l,r=0; r<n; r++){
    do_something_by_adding(nums[r]);
    while (!check_condition(k)){
        do_something_by_removing(nums[l]);
        l++;
    }
    update_the_answer();
}
 *
 */

class Solution {
public:
    int n;
    int goodLessEqualK(vector<int>& nums, int k) {
        int distinct = 0;
        int freq[20001] = {0};
        int cnt = 0;
        for (int l = 0, r = 0; r < n; r++) {
            int x = nums[r];
            freq[x]++;
            distinct += (freq[x] == 1);
            while (distinct > k) {
                int y = nums[l];
                int f = --freq[y];
                distinct -= (freq[y] == 0);
                l++;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        n = nums.size();
        return (k == 0) ? goodLessEqualK(nums, 1)
                        : goodLessEqualK(nums, k) - goodLessEqualK(nums, k - 1);
    }
};


