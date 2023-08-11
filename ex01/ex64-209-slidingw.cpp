/*
 * leetcode 209
 * min sub array length
 * whose sum greater or equal to a target
 *
 * sliding window
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, wStart = 0;
        int len = INT_MAX;
        for(int wEnd = 0; wEnd < nums.size(); wEnd++) {
            sum += nums[wEnd];
            // if greater, then reduce the window
            while(sum >= s) {
                len = min(len, wEnd-wStart+1);
                // reduce the window size by increment wStart
                // at the same time, remove that from the sum of the window 
                sum -= nums[wStart++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};

int main() {
    int a[] = {2, 3, 1, 2, 4, 3};
    int s1 = 7;
    vector<int> v1(a, a+sizeof(a)/sizeof(int));

    Solution s;

    int ans = s.minSubArrayLen(s1, v1);
    if (ans == 2) {
        cout << "test1 OK" << endl;
    } else { 
        cout << "test1 failed" << endl;
    }

    return 0;
}
