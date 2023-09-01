/*
 * leetcode 338 counting bits
 * n, [0, n], for each number, how many ones in its binary representation 
 */

// this is a special built-in function
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for (int i = 0; i <= n; i++) {
            res[i] = __builtin_popcount(i);
        }
        return res;    
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        for (int i = 1; i <= n; i++) {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;    
    }
};
