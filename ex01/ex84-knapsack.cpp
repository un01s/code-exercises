/*
 * knapsack
 *
 * this is a multiple knapsack problem
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

void test_multi_pack() {
    int a[] = {1, 3, 4};
    int b[] = {15, 20, 30};
    int c[] = {2, 3, 2};

    vector<int> weight(a, a+sizeof(a)/sizeof(int));
    vector<int> value(b, b+sizeof(b)/sizeof(int));
    vector<int> nums(c, c+sizeof(c)/sizeof(int));

    int bagWeight = 10;
    for (int i = 0; i < nums.size(); i++) {
        while (nums[i] > 1) { // till nums[i] is 1
            weight.push_back(weight[i]);
            value.push_back(value[i]);
            nums[i]--;
        }
    }

    vector<int> dp(bagWeight + 1, 0);
    for(int i = 0; i < weight.size(); i++) { // objects
        for(int j = bagWeight; j >= weight[i]; j--) { // knapsack volume
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
        for (int j = 0; j <= bagWeight; j++) {
            cout << dp[j] << " ";
        }
        cout << endl;
    }
    cout << dp[bagWeight] << endl;

}
int main() {
    test_multi_pack();
}

