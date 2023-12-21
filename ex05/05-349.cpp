/*
 * leetcode 349
 * intersection of two arrays
 *
 */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; 
        // use set for the result
        // set can remove the duplicates
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            // check if the element in nums2 appeared in nums1
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

