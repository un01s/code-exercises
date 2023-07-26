/*
 * leetcode 1005
 *
 *
 *
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }
    int largestSumAfterKNegations(vector<int>& A, int K) {
        // from absolute max to min
        sort(A.begin(), A.end(), cmp);
        // traverse the whole array
        for (int i = 0; i < A.size(); i++) {
            // turn max negative number into positive
            if (A[i] < 0 && K > 0) {
                A[i] *= -1;
                K--;
            }
        }
        // 
        // possible turn min value into negative
        if (K%2 == 1) A[A.size()-1] *= -1; 
        // sum up 
        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            res += A[i];
        }
        return res;
    }
};

int main() {
    return 0;
}
