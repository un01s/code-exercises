
class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) 
    {
        vector<vector<long> > dp(goal+1,vector<long>(n+1,0));
        dp[1][1] = n;
        long MOD = 1e9+7;
        
        for (int i=2; i<=goal; i++)
            for (int j=1; j<=min(n,i); j++)
            {
                if (j>k) dp[i][j] += dp[i-1][j]*(j-k);
                dp[i][j]%=MOD;
                if (n>j-1) dp[i][j] += dp[i-1][j-1]*(n-j+1);
                dp[i][j]%=MOD;                
            }
        
        return dp[goal][n];
    }
};

