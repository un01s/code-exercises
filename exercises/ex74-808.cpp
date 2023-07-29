/*
 * leetcode 808
 * soup servings
 *
 * dp
 * 25ml as one serving.
 * the 4 servings: 
 * - 4A, 0B
 * - 3A, 1B
 * - 2A, 2B
 * - 1A, 3B
 * at least one serving of A, total 4 servings?
 * 
 * bottom-up dp or top-down dp?
 * 
 * OK
 */

class Solution {
public:
    double soupServings(int n) {
        // N is big enough, no need to compute.
        if(n > 5000) return 1;
        // Ceil and regularize N
        n = (n + 24) / 25;
        vector<vector<double>> mem(205,vector<double>(205,-1));
        return serve(n, n, mem);
   
    }

    double serve(int A, int B,vector<vector<double>> & mem){
        if(A <= 0 && B <= 0) return 0.5;
        if(A <= 0) return 1;
        if(B <= 0) return 0;
        if(mem[A][B] != -1) return mem[A][B];
        mem[A][B] = 0.25 * (serve(A - 4, B, mem) + serve(A - 3, B - 1, mem) + serve(A - 2, B - 2, mem) + serve(A - 1, B - 3, mem));
        return mem[A][B];
    }
};

