/*
 * leetcode 416 
 *
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 100
 *
 * sum/2
 * value of numbers
 * only once - 0/1 
 *
 * dp[i]: 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum%2 == 1) return false;

        int target = sum/2;
        vector<int> dp(10001, 0);
        for(int i = 0; i < nums.size(); i++) {
            for(int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j-nums[i]]+nums[i]);
            }
        }
        if (dp[target] == target) return true;
        return false;
    }
};

int main() {
    int a[] = {1, 5, 11, 5};
    int b[] = {1, 2, 3, 5};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
    vector<int> v2(b, b+sizeof(b)/sizeof(int));
    Solution s;

    if (s.canPartition(v1)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (s.canPartition(v2) == false) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    return 0;
}
