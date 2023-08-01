# 0-1 knapsack problem 

this problem is one type of problems that can be solved by dynamic programming. it can be solved by GRASP or TABU too.

## description

```
knapsack
      └── max volume
objects
      ├── value
      ├── volume
      └── number of objects 
                     ├── only one object (yes or no) -- 0-1 knapsack
                     ├── infinity                    -- complete knapsack
                     ├── different objects of different num
                     └── grouping: one from each group
```

## 0-1 knapsack

There are objects, each has only one piece. Each has different weight and value.

| objects | weight | value |
| ------- | ------ | ----- |
| Obj1 | 1 | 15 |
| Obj2 | 3 | 20 |
| Obj3 | 4 | 30 |

There is one knapsack that could hold max weight of 4. How to get the max value?

dp[i][j]: take object from 0 to i, and put them into the knapsack that holds max j.
* no object i: a = dp[i-1][j]
* with object i: b = dp[i-1][j-weight[i]] + value[i]

So dp[i][j] = max(a, b).

to visualize how to initialize ```dp[i][j]```:

| i:j | 0 | 1 | 2 | 3 | 4 |
| --- | - | - | - | - | - |
| Obj0 |0 | 15 | 15 | 15 | 15 |
| Obj1 |0 | 0 | 0 | 0 | 0 |
| Obj2 |0 | 0 | 0 | 0 | 0 |


