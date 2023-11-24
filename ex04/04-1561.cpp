/*
 * leetcode 1561
 * max number of coins you can get
 *
 */

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // sort the piles in non-increasing order
        sort(piles.begin(), piles.end(), greater<int>());
        
        // greedy using two-pointers
        int sum = 0;
        for (int l = 0, r = piles.size() - 1; l < r; l += 2, r--) {
            sum += piles[l + 1];
        }
        return sum;    
    }
};

