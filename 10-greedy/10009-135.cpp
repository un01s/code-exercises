/*
 * leetcode 135
 *
 *
 *
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// greedy
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> res(ratings.size(), 1); // at one candy for each kid
        // from left to right
        for(int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) res[i] = res[i-1]+1;
        }
        // from right to left
        for(int i = ratings.size()-2; i >= 0; i--) {
            if (ratings[i]  > ratings[i+1]) res[i] = max(res[i], res[i+1]+1);
        }

        int total = 0;
        for(int i = 0; i < res.size(); i++) {
            total += res[i];
        }
        return total;
    }
};


int main() {
    return 0;
}
