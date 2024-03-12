/*
 * leetcode 1498
 * number of subsequences that satisfy the given sum condition
 * 
 * subsequence is the key, it has nothing to do with its order
 * sort the nums first
 */

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long M = 1e9 + 7;
        long ret = 0;
        vector<long> power(n + 1);
        power[0] = 1;
        for (int i = 1; i <= n; i++)
            power[i] = power[i - 1] * 2 % M;

        int j = n - 1;
        for (int i = 0; i < n; i++) {
            while (j >= 0 && nums[i] + nums[j] > target)
                j--;
            if (j < i)
                break;
            ret = (ret + power[j - i]) % M;
        }
        return ret;
    }
};

// double-pointer
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> pow2mod(n + 1, 1);
        for (int exp = 1; exp <= n; exp++)
            pow2mod[exp] = (pow2mod[exp - 1] << 1) % mod;

        int l = 0, r = n - 1;
        int result = 0;
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                result = (result + pow2mod[r - l]) % mod;
                l++;
            } else
                r--;
        }
        return result;
    }
};
