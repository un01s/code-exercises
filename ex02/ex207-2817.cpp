/*
 * leetcode 2817
 * minimum absolute difference between elements with constraint
 *
 * 
 * Input: nums = [4,3,2,4], x = 2
 * Output: 0
 *
 * Input: nums = [5,3,2,10,15], x = 1
 * Output: 1
 * 
 * Input: nums = [1,2,3,4], x = 3
 * Output: 3
 *
 * at least x apart in their indice
 * for each element, find its immediate greater and smaller element
 * look for only on one side of element. the other side will be considered later * 
 * set, upper_bound
 * iterator
 *
 */

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int ans = INT_MAX;
        set<int> s;
        for(int i = x; i < nums.size(); i++) {
            // insert i-x element to set
            s.insert(nums[i-x]);
            // find immediate greater element in set
            auto it = s.upper_bound(nums[i]);
            // diff with greater element
            if (it != s.end())
                ans = min(ans, *it -nums[i]);
            // diff with <=
            if (it != s.begin()) {
                ans = min(ans, nums[i]- *prev(it));
            }
        }
        return ans;
    }
};

