/*
 * leetcode 2997
 * minimum number of operations to make array XOR equal to K
 *
 */

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < 31; i++) {
            int mask = 1 << i;
            int r = k & mask;
            int c = 0;
            for (int x : nums) {
                if (mask & x)
                    c++;
            }
            if (r != 0 && c % 2 == 0)
                ans++;
            else if (r == 0 && c % 2 != 0)
                ans++;
        }
        return ans;
    }
};

