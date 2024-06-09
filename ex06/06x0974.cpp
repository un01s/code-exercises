/*
 * leetcode 974
 * subarray sums divisible by K
 * 
 */

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mod_k(k, 0); // 2 <= k <= 10^4 array is good
        int prefix = 0;
        mod_k[0] = 1; // consider prefix sums that are directly divisible by k

        for (int x : nums) {
            prefix = (prefix + x) % k;
            prefix += ((prefix < 0) ? k : 0);
            mod_k[prefix]++;
        }
        return accumulate(mod_k.begin(), mod_k.end(), 0,
                          [](int sum, int x) { return sum + x * (x - 1) / 2; });
    }
};

// recursive
class Solution {
public:
    vector<int> mod_k;
    int f(int i, int prefix, vector<int>& nums, int k) {
        if (i < 0)
            return 0; // base case
        prefix = (prefix + nums[i]) % k;
        prefix += ((prefix < 0) ? k : 0);
        int ans = mod_k[prefix];
        mod_k[prefix]++;
        ans += f(i - 1, prefix, nums, k); // recursive calling
        mod_k[prefix]--;                  // Backtracking
        return ans;
    }

    int subarraysDivByK(vector<int>& nums, int k) {
        const int n = nums.size();
        mod_k.assign(k, 0);
        int prefix = 0;
        mod_k[0] = 1; // consider prefix sums that are directly divisible by k

        return f(n - 1, 0, nums, k);
    }
};

