/*
 * leetcode 96
 * different binary search tree
 * 
 * given n, how many binary search trees with from 1 to n nodes?
 *
 * n = 1
 * 1
 *
 * n = 2
 * 1        2
 *  \  or  /
 *   2    1
 *
 * 
 * n = 3
 *
 * 1        1          2         3      3
 *  \        \        / \       /      /
 *   2   or   3  or  1   3 or  2   or 1
 *    \      /                /        \
 *     3    2                1          2
 *
 * when n=3 and 1 is the root node, its right/left sub-tree like n=2
 * when n=3 and 3 is the root node, its subtrees like n=2
 * when n=3 and 2 is the root node, its subtrees like n=1
 *
 * dp[3] = sum of node 1, node 2, or node 3 as the root node 
 * 
 * 
 */

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};



