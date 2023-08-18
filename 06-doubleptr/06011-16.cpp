/*
 * leetcode 16
 *
 * double pointers
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // must sort first
        // this makes the pointer moving meaningful
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int res;
        int tmp = INT_MAX;
        for (int i = 0; i < n; i++) {
            int left = i+1;
            int right = n-1; // the end
            int sum = target - nums[i];

            while (left < right) {
                if (tmp > abs(nums[left]+nums[right]-sum)) {
                    // update the minimum result
                    tmp = abs(nums[left]+nums[right]-sum);
                    res = nums[i]+nums[left]+nums[right];
                }

                if (nums[left]+nums[right] == sum) return target;
                else if (nums[left]+nums[right] > sum) right--;
                else if (nums[left]+nums[right] < sum) left++;            
            }      
        }

        return res;
    }
};

int main() {
    int a[] = {-1, 2, 1, -4};
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
    int t1 = 1;
    int b[] = {0, 0, 0};
    vector<int> v2(b, b+sizeof(b)/sizeof(int));
    int t2 = 1;

    Solution s;

    if (s.threeSumClosest(v1, t1) == 2) {
        cout << "test1 OK" << endl;
    } else {
        cout << "test1 failed" << endl;
    }

    if (s.threeSumClosest(v2, t2) == 0) {
        cout << "test2 OK" << endl;
    } else {
        cout << "test2 failed" << endl;
    }

    return 0;
}
