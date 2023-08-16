/*
 * leetcode 862
 * shortest subarray with sum at least K
 *
 * use deque
 *
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> presum(n+1);
        for (int i=0; i<n; i++)
            presum[i+1] = presum[i]+nums[i];

        int res = INT_MAX;
        deque<int> dq;
        
        for (int i=0; i<=n; i++)
        {
            while (!dq.empty() && presum[dq.back()] >= presum[i])
                dq.pop_back();

            while (!dq.empty() && presum[i]-presum[dq.front()] >= k) {           
                res = min(res, i-dq.front());
                dq.pop_front();
            }

            dq.push_back(i);
        }

        if (res == INT_MAX) return -1;
        else return res;
    }
};

int main() {
    int a[] = {2, -1, 2};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
    int k1 = 3;

    Solution s;
    if (s.shortestSubarray(v1, k1) == 3) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    return 0;
}
