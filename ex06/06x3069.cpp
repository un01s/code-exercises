/*
 * leetcode 3069
 *
 */

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
      vector<int> arr1 = {nums[0]}, arr2 = {nums[1]};
      for (int i = 2; i < n; ++i) {
        if (arr1.back() > arr2.back()) arr1.push_back(nums[i]);
        else arr2.push_back(nums[i]);
      }
      for (int x : arr2) arr1.push_back(x);
      return arr1;
    }
};

