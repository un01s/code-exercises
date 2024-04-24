/*
 * leetcode 1137
 * n-th tribonacci number
 * 
 */

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        else if (n <= 2)
            return 1;
        tuple<int, int, int> t = {0, 1, 1};
        for (int i = 3; i <= n; i++) {
            auto [x, y, z] = t;
            t = {y, z, x + y + z};
        }
        return get<2>(t);
    }
};

// recursion
class Solution {
public:
    int t[38];
    int f(int n) {
        if (t[n] != -1)
            return t[n];
        switch (n) {
        case 0:
            return t[n] = 0;
        case 1:
        case 2:
            return t[n] = 1;
        default:
            return t[n] = f(n - 3) + f(n - 2) + f(n - 1);
        }
    }

    int tribonacci(int n) {
        fill(t, t + 38, -1);
        return f(n);
    }
};
