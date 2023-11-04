/*
 * leetcode 239
 * max in the sliding window
 *
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // deque
        int n = nums.size();
        if (n == 0 || k == 0) return {};
        deque<int> q;
        vector<int> res(n-k+1);
        // initialize
        for (int j = 0, i = 1-k; j < n; i++, j++) {
            // delete nums[i-1]
            if (i > 0 && q.front() == nums[i-1])
                q.pop_front();
            // main decreasing q
            while(!q.empty() && q.back() < nums[j])
                q.pop_back();
            q.push_back(nums[j]);
            // record the max in the window
            if (i >= 0)
                res[i] = q.front();
        }
        // return
        return res;
    }
};

