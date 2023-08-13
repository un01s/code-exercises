/*
 * leetcode 2815
 *
 * You are given a 0-indexed integer array nums. You have to find the maximum 
 * sum of a pair of numbers from nums such that the maximum digit in both 
 * numbers are equal.
 * 
 * Return the maximum sum or -1 if no such pair exists.
 *
 * 1) max sum of a pair of num
 * 2) same max digit in both numbers
 *
 * examples:
 * input: nums = [51, 71, 17, 24, 42]
 * output: 88
 * 
 * input: nums = [1, 2, 3, 4]
 * output: -1
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int maxNumForDigit[10] = {0};
        int ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            int t = nums[i];
            cout << "num[" << i << "]=" << t << endl;
            int maxD = 0;
            while(t) {
                int r = t%10;
                maxD = max(maxD, r); // 1-position
                t /= 10; // 10-position
                cout << "digits:" << t << "-" << r << endl;
                cout << "maxD:" << maxD << endl;
            }
            // if pair exists
            if (maxNumForDigit[maxD]) ans = max(ans, maxNumForDigit[maxD]+nums[i]);
            
            // update max num for this digit
            if (nums[i] > maxNumForDigit[maxD]) maxNumForDigit[maxD] = nums[i];
            
            cout << "ans=" << ans << endl;
            cout << "maxNumForDigit: ";
            for (int j = 0; j < 10; j++) {
                cout << maxNumForDigit[j] << " ";
            }
            cout << endl;
        }
        return ans;    
    }
};

int main() {
    int a[] = {51,71,17,24,42};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
    int b[] = {1, 2, 3, 4};
    vector<int> v2(b, b+sizeof(b)/sizeof(int));
    int c[] = {4, 3, 31, 14, 23, 5};
    vector<int> v3(c, c+sizeof(c)/sizeof(int));

    Solution s;
    if (88 == s.maxSum(v1)) {
        cout << "Test1 OK" << endl;
    } else {
        cout << "Test1 failed" << endl;
    }

    if (-1 == s.maxSum(v2)) {
        cout << "Test2 OK" << endl;
    } else {
        cout << "Test2 failed" << endl;
    }

    if (54 == s.maxSum(v3)) {
        cout << "Test3 OK" << endl;
    } else {
        cout << "Test3 failed" << endl;
    }

    return 0;    
}
