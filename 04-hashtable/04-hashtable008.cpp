/**
 * 15 three sum
 * https://leetcode.com/problems/3sum/
 * 
 * Given an integer array nums, return all the triplets 
 * [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and 
 * nums[i] + nums[j] + nums[k] == 0.
 * 
 * Notice that the solution set must not contain duplicate triplets.
 *
 * Two loops to get a+b, then use hash-table to find out if 0-(a+b)
 * is in the array. The problem is that the answer should NOT have duplicates.
 * To remove the duplicates in the vector is time consuming.
 *
 * 20230630
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// hash-table
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        // find a + b + c = 0
        // a = nums[i]
        // b = nums[j]
        // c = 0-(a+b)
        for (int i = 0; i < nums.size(); i++) {
            //
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i-1]) {
                continue; // duplicate a
            }
            unordered_set<int> s;
            for (int j = i+1; j < nums.size(); j++) {
                if (j > i+2
                        && nums[j] == nums[j-1]
                        && nums[j-1] == nums[j-2]) {
                    continue; // duplcate b
                }
                int c = 0 - (nums[i] + nums[j]);
                if (s.find(c) != s.end()) {
                    int a[] = {nums[i], nums[j], c};
                    vector<int> v(a, a + sizeof(a)/sizeof(int));
                    //result.push_back({nums[i], nums[j], c});
                    result.push_back(v);
                    cout << "{" << nums[i] << "," << nums[j] << "," << c << "}\n";
                    s.erase(c); // no duplcate c
                } else {
                    s.insert(nums[j]);
                }
            }
        }
        return result;        
    }
};

class Solution2 {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                return result; // no solution because the first is already greater than 0 in a sorted array
            }
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i+1;
            int right = nums.size()-1;
            while ( right > left) {
                if (nums[i]+nums[left]+nums[right] > 0) {
                    right--;
                } else if (nums[i]+nums[left]+nums[right] < 0) {
                    left++; // typo -- causes a segmentation fault
                } else {
                    int a[] = {nums[i], nums[left], nums[right]};
                    vector<int> v(a, a+sizeof(a)/sizeof(int));
                    result.push_back(v);
                    cout << nums[i] << "," << nums[left] << "," << nums[right] << endl;
                    while(right>left && nums[right]==nums[right-1]) right--;
                    while(right>left && nums[left]==nums[left+1]) left++;
                    // since one solution is found
                    right--;
                    left--;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;

    int n[] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums(n, n+sizeof(n)/sizeof(int));
    s.threeSum(nums);
//  $./a.out 
//  {-1,1,0}
//  {-1,2,-1}
    
    Solution2 s2;
    int m[] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums2(m, m+sizeof(m)/sizeof(int));
    s2.threeSum(nums2);

    return 0;
}
