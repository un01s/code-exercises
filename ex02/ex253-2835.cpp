/*
 * leetcode 2835
 *
 * greedy
 * 
 */

class Solution {
public:
    int minOperations(vector<int> &nums, int target) {
        if (accumulate(nums.begin(), nums.end(), 0LL) < target)
            return -1;
        long long cnt[31]{};
        for (int x: nums)
            cnt[__builtin_ctz(x)]++;
        int res = 0, i = 0;
        long long s = 0;
        while ((1LL << i) <= target) {
            s += cnt[i] << i;
            int mask = (1LL << ++i) - 1;
            if (s >= (target & mask))
                continue;
            res++;
            for (; cnt[i] == 0; i++)
                res++;
        }
        return res;
    }
};

