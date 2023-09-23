/*
 * leetcode 2848
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

class Solution2 {
public:
    int numberOfPoints(vector<vector<int> >& nums) {
        vector<int> a(101);
        for(auto& q:nums){
            for(int i=q[0];i<=q[1];++i)
                a[i]=1;
        }
        int res=0;
        for(int q:a)
            res+=q;
        return res;
    }
};

