/*
 * leetcode 712
 * minimum ASCII delete sum for two strings
 *
 * Given two strings s1 and s2, return the lowest ASCII sum of deleted 
 * characters to make two strings equal.
 *
 */

class Solution {
public:
    // DP 
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        
        vector<vector<int>> dp(m+1, vector(n+1, 0));
        
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 0;
                }else if(j == 0){
                    dp[i][j] = dp[i-1][j] + s1[i-1];
                }else if(i == 0){
                    dp[i][j] = dp[i][j-1] + s2[j-1];
                }else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(
                        dp[i-1][j] + s1[i-1],
                        dp[i][j-1] + s2[j-1]
                    );
                }
            }
        }
        
        return dp[m][n];    
    }
};

