/*
 * leetcode 63 unique paths II
 */

// obstacles added
// 1. dp[i][j]: paths to (i,j} from [0,0)
// 2. dp[i][j] = dp[i-1][j] + dp[i][j-1]
//    if any obstacles, remain initial state
//    if (obstacleGrid[i][j] == 0) { // no obstacle case
//    }
// 3. initialization
//    vector<vector<int> > dp(m, vector<int>(n, 0));
//    for (int i = 0; i < m; i++) dp[i][0] = 1;
//    for (int j = 0; j < n; j++) dp[0][j] = 1;
//    if any obstacles, after obstacle, it should be 0 instead of 1.
//    add another condition to ensure that grid is not obstacle
//    not obstacle: obstacleGrid[i][0] == 0
//    this added condition is to stop the initialization
// 4 the order of traversal
// 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1) {
            return 0;
        }
       
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for (int j = 0; i < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i-1][j] + dp[i][i-1];
            }
        }
        return dp[m-1][n-1];
    }
};
