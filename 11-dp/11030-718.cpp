/*
 * leetcode 718
 *
 * DP
 *
 * dp[i][j]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        vector<vector<int> > dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j < nums2.size(); j++) {
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                if (dp[i][j] > res) res = dp[i][j];
            }
        } 
        return res;
    }
};

int main() {
    int a[] = {1, 2, 3, 2, 1};
    int b[] = {3, 2, 1, 4, 7};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
    vector<int> v2(b, b+sizeof(b)/sizeof(int));

    Solution s;

    if (3 == s.findLength(v1, v2)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    return 0;
}
