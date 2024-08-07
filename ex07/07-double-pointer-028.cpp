/*
 * leetcode 1004
 *
 * double-pointer, DP is OK too.
 *
 */

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int j = 0;
        int ret = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && (nums[j] == 1 || (nums[j] == 0 && count < k))) {
                if (nums[j] == 0)
                    count++;
                j++;
            }
            ret = max(ret, j - i);
            if (nums[i] == 0)
                count--;
        }
        return ret;
    }
};

// DP
class Solution2 {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int i = 0;
        int ret = 0;
        for (int j=0; j<n; j++)
        {
            if (nums[j]==1)
            {
                ret = max(ret, j-i+1);
                continue;
            }
                
            count++;
            while (count>k)
            {
                if (nums[i]==0)
                    count--;
                i++;
            }
            ret = max(ret, j-i+1);
        }
        return ret;
    }
};

