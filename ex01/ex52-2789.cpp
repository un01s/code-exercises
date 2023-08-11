/* 
 * leetcode 2789
 * Largest Element in an Array after Merge Operations
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;
        long long result = 0;
        long long sum = nums[i];
        while (i > 0) {
            if (sum >= nums[i-1]) sum += nums[i-1];
            else sum = nums[i-1];
            i--;
        }
        result = max(sum, result);
        return result;
    }
};

int main() {
    return 0;
}

