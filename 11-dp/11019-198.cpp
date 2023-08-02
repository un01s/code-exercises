/*
 * leetcode 198
 * 
 * to rob one house or not depends on the status of the last house or 
 * the last two houses.
 * 1) no robbing in two neighboring houses (it triggers the alarm)
 * 2) maximize the money robbed
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

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        
        return dp[nums.size()-1];
    }
};

int main() {
    int a[] = {1, 2, 3, 1};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
    int b[] = {2, 7, 9, 3, 1};
    vector<int> v2(b, b+sizeof(b)/sizeof(int));

    Solution s;

    if (4 == s.rob(v1)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (12 == s.rob(v2)) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    return 0;
}
