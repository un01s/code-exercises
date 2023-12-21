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

// another way to use array
// because the constraint states that 
// 0 <= nums1[i], nums2[i] <= 1000
// and the size of each array is also
// 1 <= nums1.size(), nums2.size() <= 1000
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        // use the set for the result to remove duplicates

        int hash[1005] = {0}; // because of the constraints
        for (int num : nums1) { // record every element of nums1 into hash
            hash[num] = 1;
        }
        for (int num : nums2) { // check if the element of nums2 is in nums1
            if (hash[num] == 1) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

