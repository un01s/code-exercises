/*
 * leetcode 2917
 * find the K-or of an array
 *
 */

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i <= 30; i++){
            int cnt = 0;
            for(int j = 0; j < nums.size(); j++){
                if((nums[j]>>i)&1) cnt++;
            }
            if(cnt >= k) ans |= 1<<i;
        }
        return ans;    
    }
};

