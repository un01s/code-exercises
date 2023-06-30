/**
 * 18 4sum
 * https://leetcode.com/problems/4sum/
 * 
 * Given an array nums of n integers, return an array of all the unique 
 * quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 * 
 * 0 <= a, b, c, d < n
 * a, b, c, and d are distinct.
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 * 
 * You may return the answer in any order.
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// double-pointers
class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        <vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // trim
            if (nums[i]>target && nums[i]>=0) {
                break;
            }
            // trim nums[i]
            if (i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            for (int j = i+1; j < nums.size(); j++) {
                // second-level trim
                if (nums[i]+nums[j]>target && nums[i]+nums[j]>=0) {
                    break;
                } 
                if (j>i+1 && nums[j]==nums[j-1]) {
                    continue;
                }
                int left = j+1;
                int right = nums.size()-1;
                while(right > left) {
                    if ((long)nums[i]+nums[j]+nums[left]+nums[right] > target) {
                        right--;
                    } else if ((long)nums[i]+nums[j]+nums[left]+nums[right] < target) {
                        left++;
                    } else {
                        int n[] = {nums[i], nums[j], left, right};
                        vector<int> v(n, n+sizeof(n)/sizeof(int));
                        result.push_back(v);
                        cout << nums[i] << "";
                        cout << nums[j] << "";
                        cout << left << "";
                        cout << right << endl;
                        while(right>left && nums[right]==nums[right-1]) right--;
                        while(right>left && nums[left]==nums[left+1]) left++;
                        //
                        right--;
                        left++;
                    }
                  
                }
            }
        }
        return result;
    }
};

int main() {
    int a[] = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    vector<int> v1(a, a+sizeof(a)/sizeof(int));
    // [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

    int b[] = {2, 2, 2, 2};
    int target2 = 8;
    vector<int> v2(b, a+sizeof(b)/sizeof(int));
    // [[2,2,2,2]]

    Solution s;
    s.fourSum(v1, target1);
    s.fourSum(v2, target2);
    
    return 0;
}
