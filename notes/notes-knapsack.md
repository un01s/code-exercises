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

The state of each object is either in the knapsack or not.

There is one knapsack that could hold max weight of 4. How to get the max value?

Definition of dp[i][j]: the max value of taking object from 0 to i, and put them into the knapsack that holds max weight of j.

* no object i: a = dp[i-1][j]
* with object i: b = dp[i-1][j-weight[i]] + value[i]

So dp[i][j] = max(a, b).

to visualize how to initialize ```dp[i][j]```:

| i:j | 0 | 1 | 2 | 3 | 4 |
| --- | - | - | - | - | - |
| Obj0 |0 | 15 | 15 | 15 | 15 |
| Obj1 |0 | 0 | 0 | 0 | 0 |
| Obj2 |0 | 0 | 0 | 0 | 0 |

How to traverse? Need two loops. One for objects and the other for knapsacks.

The order of traverse for 0-1 knapsack (2D dp[i][j]) does not matter. Either object-first or knapsack-first is OK.

### What if we are using only 1-D array?

* dp[j]: the max value for the knapsack whose max weight of j.
* dp[j] = max(dp[j], dp[j - weight[i]] + value[i])

```C++
for (int i = 0; i < weight.size(); i++) {
    for(int j = badweight; j >= weigth[i]; j--) {
        dp[j] = max(dp[j], dp[j-weight[i]]_value[i]);
    }
}
```

So the traversal order is that first-loop for objects, and the second loop for knapsacks in reverse to ensure that object i is used only once in the knapsack.

## complete knapsack

There are N objects and one knapsack that could hold max weight of W. The i-th object weighs of weight[i] and has the value of value[i]. There are infinite number of each object. That is the difference from 0-1 knapsack.

## multiple knapsack

Each object has limited number, not one piece and not infinite.

|   | weight | value | quantity |
| - | ------ | ----- | -------- |
| Obj0 | 1 | 15 | 2 |
| Obj1 | 3 | 20 | 3 |
| Obj2 | 3 | 30 | 2 |

The knapsack could hold the max weight of 10. The question is that what is the maximum value the knapsack could hold?

Check the code of [ex84](https://github.com/un01s/code-exercises/blob/main/exercises/ex84-knapsack.cpp).

Below is the dp[i][j] table. The row is for each object. The column is for weight.

```
0 15 15 15 15 15 15 15 15 15 15 
0 15 15 20 35 35 35 35 35 35 35 
0 15 15 20 35 45 45 50 65 65 65 
0 15 30 30 35 50 60 60 65 80 80 
0 15 30 30 35 50 60 60 70 80 80 
0 15 30 30 35 50 60 60 70 80 80 
0 15 30 30 35 50 60 60 70 80 90 
90
```

this problem could be transformed into 0-1 knapsack as follows:

|   | weight | value | quantity |
| - | ------ | ----- | -------- |
| Obj0 | 1 | 15 | 1 |
| Obj0 | 1 | 15 | 1 |
| Obj1 | 3 | 20 | 1 |
| Obj1 | 3 | 20 | 1 |
| Obj1 | 3 | 20 | 1 |
| Obj2 | 3 | 30 | 1 |
| Obj2 | 3 | 30 | 1 |

In the case each object can be used only once. So the object is either in the knapsack or not. This is a 0-1 knapsack problem.


