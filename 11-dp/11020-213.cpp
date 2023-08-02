/*
 * leetcode 213
 * 
 * to rob one house or not depends on the status of the last house or 
 * the last two houses.
 * 1) no robbing in two neighboring houses (it triggers the alarm)
 * 2) maximize the money robbed
 *
 * 3) the houses form a ring, the head and tail are neighbors.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        // case2: has the head, no tail
        int res1 = robRange(nums, 0, nums.size()-2);
        // case3: has the tail, no head
        int res2 = robRange(nums, 1, nums.size()-1);
        return max(res1, res2);
    }

    int robRange(vector<int>& nums, int start, int end) {
        if (end == start) return nums[start];

        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start+1] = max(nums[start], nums[start+1]);

        for (int i = start+2; i <= end; i++) {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        
        return dp[end];
    }
};

int main() {
    int a[] = {2, 3, 2};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
    int b[] = {1, 2, 3, 1};
    vector<int> v2(b, b+sizeof(b)/sizeof(int));

    Solution s;

    if (3 == s.rob(v1)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (4 == s.rob(v2)) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    return 0;
}
