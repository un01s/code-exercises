/*
 * Q1
 */

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int ans=0;
        for (int i=1; i<=100; ++i) {
            bool ok=0;
            for (auto x : nums)
                ok|=x[0]<=i&&i<=x[1];
            ans+=ok;
        }
        return ans;
    }
};

