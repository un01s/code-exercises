###
  leetcode 583
  https://www.youtube.com/@codeyao9796

  [1, 500]
  only lowercase English letters
 
  DP
  dp[i][j] := number of deletions word1[:i] and word2[:j]
  
  if equal:
      dp[i][j] = dp[i-1][j-1]
  else:
      dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1)

    "" s e a
""  0  1 2 3
e   1  2 1 2
a   2  3 2 1
t   3  4 3 2
 
    return 2
###

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        dp = [[0]*(n+1) for _ in range(m+1)]
        for j in range(1, n+1):
            dp[0][j] = j;
        for i in range(1, m+1):
            dp[i][0] = i;
        for i in range(1, m+1):
            for j in range(1, n+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = dp[i-1][j-1]
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1])
        return dp[m][n]
