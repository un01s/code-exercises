/*
 * leetcode 1049
 * https://leetcode.com/problems/last-stone-weight-ii/
 *
 * solution:
 *
 * divide rocks into two groups with equal weight so that the remaining is the
 * minimum.
 *
 * weight: stones[i]
 * value: stones[i]
 *
 * dp[j] knapsack with max weight of j (or volume of j)
 * dp[j] = max(dp[j], dp[j-weight[i]]+value[i])
 * so, dp[j] = max(dp[j], dp[j-stones[i]]+stones[i]);
 *
 * 1 <= stones.length <= 30
 * 1 <= stones[i] <= 1000
 * so the max total weigth is 30,000.
 * then the half of it is 15,000.
 * 
 * the weight won't be negative. dp[j] are all initialized to 0.
 * vector<int> dp(15001, 0);
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> dp(15001, 0);
        int sum = 0;
        for (int i = 0; i < stones.size(); i++) {
            sum += stones[i];
        }
        int target = sum/2;
        for (int i = 0; i < stones.size(); i++) { // objects
            for (int j = target; j >= stones[i]; j--) { // knapsacks
                dp[j] = max(dp[j], dp[j-stones[i]]+stones[i]);
            }
        }
        
        return (sum-dp[target])-dp[target];        
    }
};

int main() {
    int a[] = {2, 7, 4, 1, 8, 1};
    int b[] = {31, 26, 33, 21, 40};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
    vector<int> v2(b, b+sizeof(b)/sizeof(int));

    Solution s;
    if (s.lastStoneWeightII(v1) == 1) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (s.lastStoneWeightII(v2) == 5) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    return 0;
}
