/*
 * leetcode 1425
 * constrained subsequence sum
 *
 * use deque to maintain a monotonic queue
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n,0);
        deque<int> q;
        
        int res = INT_MIN;
        for (int i=0; i<n; i++){
            while (q.size()>0 && q.front() < i-k)
                q.pop_front();
            
            dp[i] = nums[i];
            if (q.size()>0) dp[i] = max(dp[i], dp[q.front()] + nums[i]);            
            
            while (q.size()>0 && dp[q.back()] <= dp[i])
                q.pop_back();
            q.push_back(i);
        }
                
        for (int i=0; i<n; i++)
            res = max(res, dp[i]);
        return res;
    }
};

int main() {
    int a[] = {10, 2, -10, 5, 20};
    int k1 = 2;
    vector<int> v1(a, a+sizeof(a)/sizeof(int));

    int b[] = {-1, -2, -3};
    int k2 = 1;
    vector<int> v2(b, b+sizeof(b)/sizeof(int));

    int c[] = {10, -2, -10, -5, 20};
    int k3 = 2;
    vector<int> v3(c, c+sizeof(c)/sizeof(int));

    Solution s;

    if (37 == s.constrainedSubsetSum(v1, k1)) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (-1 == s.constrainedSubsetSum(v2, k2)) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    if (23 == s.constrainedSubsetSum(v3, k3)) {
        cout << "test3 OK" << endl;
    } else {
        cout << "test3 failed" << endl;
    }

    return 0;
}
