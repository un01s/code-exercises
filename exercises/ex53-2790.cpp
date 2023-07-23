/* leetcode 2790 
 *
 *
 * 
You are given a 0-indexed array usageLimits of length n.

Your task is to create groups using numbers from 0 to n - 1, ensuring that each number, i, is used no more than usageLimits[i] times in total across all groups. You must also satisfy the following conditions:

Each group must consist of distinct numbers, meaning that no duplicate numbers are allowed within a single group.
Each group (except the first one) must have a length strictly greater than the previous group.
Return an integer denoting the maximum number of groups you can create while satisfying these conditions.


 
 */

class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        int n = usageLimits.size();
        sort(usageLimits.begin(), usageLimits.end());
        int lb = 0;
        int ub = n + 1;
        while (lb < ub){
            int mid = (lb + ub) / 2;
            long long delta = 0;
            for (int i = n - 1; i >= 0; --i){
                if (i > n - 1 - mid){
                    delta += usageLimits[i] - (mid - (n - 1 - i));
                }
                delta = min(delta, (long long)0);
                if (i <= n - 1 - mid){
                    delta += usageLimits[i];
                }
            }
            if (delta >= 0){
                lb = mid + 1;
            } else {
                ub = mid;
            }
        }
        return lb - 1;
    }
};

