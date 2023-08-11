/* 
 * leetcode 713
 * subarray product less than K
 * input: [10, 5, 2, 6], k = 100
 * output: 8
 * because we have the following subarrays:
 * [[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]]
 *
 * solution:
 * use two pointer to form a sliding window
 * step1: product = 1, ans = 0;
 * step2: both left and right pointing at 10, the first element in the array
 *        product *= 10, ans += 1, so product = 10, ans = 1
 * step3: move right pointer to the second element 5.
 *        product *= 5, ans += 1, so product = 50, ans = 2
 *        so we know [10, 5] and its subarray has the product less than k
 *
 * reference:
 *
 * patterns and templates
 *
 * https://blog.techbridge.cc/2019/08/30/leetcode-pattern-two-pointer/
 * https://ithelp.ithome.com.tw/articles/10303527 
 * https://github.com/wisdompeak/LeetCode/tree/master/Template
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        
        int n = nums.size();
        int count = 0;
        int p = 1, l = 0;
        for(int r = 0; r < n; r++) {
            p *= nums[r];
            while(p >= k) {
                p /= nums[l];
                l++;
            }
            count += r - l + 1;
        }
        return count;
    }
};

int main() {
    return 0;
}
