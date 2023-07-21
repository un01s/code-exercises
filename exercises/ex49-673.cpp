class Solution {
public:
    int numOfLIS(vector<int>& nums) {
        vector<int> dp;
        for(int i = 0; i < nums.size(); i++) {
            int low = 0;
            int high = dp.size();
            while (low < high) {
                int mid = (low + high)/2;
                if (dp[mid] < nums[i]) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
                if (high == dp.size()) {
                    dp.push_back(nums[i]);
                } else {
                    dp[high] = nums[i];
                }
            }
        }
        return dp;
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;

        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        
        int maxN = 1;
        for(int i = 1; i < n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(nums[i] > nums[j] && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }else if(nums[i] > nums[j] && dp[j] + 1 == dp[i]){
                    count[i] += count[j];
                }
            }
            maxN = max(maxN, dp[i]);
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == maxN){
                res += count[i];
            }
        }
        return res;   
    }
};

