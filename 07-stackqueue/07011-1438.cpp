/*
 * leetcode 1438
 *
 */

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> qmax({0});
        deque<int> qmin({0});

        int j = 0;
        int res = 1;
        int mx = nums[0], mn = nums[0];
        for (int i=0; i<nums.size() && j<nums.size(); i++) {
            while (mx-mn <= limit) {
                res = max(res, j-i+1);
                j++;
                if (j>=nums.size()) break;

                while (qmax.size()>0 && nums[j] >= nums[qmax.back()]) {                             qmax.pop_back();                
                }
                qmax.push_back(j);
                mx = nums[qmax.front()];
                
                while (qmin.size()>0 && nums[j] <= nums[qmin.back()]) {
                    qmin.pop_back();
                }
                qmin.push_back(j);
                mn = nums[qmin.front()];
            }

            if (j>=nums.size()) break;

            if (qmax.size()>0 && qmax.front()<=i){
                qmax.pop_front();
                mx = nums[qmax.front()];
            }
            if (qmin.size()>0 && qmin.front()<=i){
                qmin.pop_front();
                mn = nums[qmin.front()];
            }
        }
        return res;
    }
};
