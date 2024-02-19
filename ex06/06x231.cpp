/*
 * leetcode 231
 * power of two
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0) return 0; else return (1<<30)%n==0;    
    }
};

