/*
 * leetcode 191
 * number of 1 bits
 * 
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return bitset<32>(n).count();    
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        if (n==0) return 0;
        unsigned ans=0;
        for(; n>0; n&=(n-1)) ans++;
        return ans;    
    }
};


