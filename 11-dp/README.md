# dynamic programming

To think about DP, there are three questions to ask:

* what is the state? 
* the definition of dp array? 
* how does states change?

## DP vs. Brute force

The key difference is that DP does not care about the specific routes but the number of routes or paths. Given a mxn matrix, how many ways to go from the top-left corner to the bottom-right corner?

* define f(i, j) as the total number of paths from (1, 1) to (i, j)

* f(i, j) = f(i-1, j) + f(i, j-1);

* once f(i, j) is known, no need to know how to get to calculate it

* the past does not depend on the future, the future does not affect on the past.

* optimal sub-structrure: the optimal solution to a big problem can be derived fom many small problems.

This means the DP can be applied to the problem where a big one can be divided into several small problems, the optinal solution to each small problem could lead to the optimal solution of the big problem.

### I. time serie

Given an array or a string, where each element can be considered as a day, the state of today can be derived only by the state of yesterday. 

* dp[i][j]: the i-th round, the j-th state (j = 1, 2, ..., K)

* find out how to reach dp[i][j] from dp[i-1][j] (j = 1, 2, ..., K)

* the final result is dp[last][j] by some kind of aggregation such as (sum, min, max, ...)

The typical problem is house robber and best to buy or sell stocks.

#### Leetcode 198

| round | state1 | state2 |
| ----- | ------ | ------ |
| (i-1)-th  | rob  | no rob |
| i-th | no rob | nor rob or rob |

The constraint is not to rob both neighbors.

```C++
// 0: the max gain by robbing at the i-th round
// 1: the max gain by not robbing at the i-th round

for(int i = 1; i <= n; i++) {
    dp[i][0] = dp[i-1][1] + val[i];
    dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
}
// ...
int answer = max(dp[n][0], dp[n][1]);
```

#### Leetcode 213 (head and tail connected)

* No robbing at the first, for the others, house[1]~house[last] as LC198.

* No robbing at the last, for the others, house[0]~house[last-1] as LC198.

#### Leetcode 123 best time to buy and sell stock III

#### Leetcode 309 best time ot buy and sell stock with cooldown

#### Leetcode 376 longest wiggle subsequence

#### Leetcode 276 paint fence (neighboring house should not has the same color)

#### Leetcode 487 max consecutive ones II

#### leetcode 1186 maximum subarray sum with one deletion






