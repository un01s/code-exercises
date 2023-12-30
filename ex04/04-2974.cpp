/*
 * leetcode 2974
 * minimum number game
 * 
 */

//
// sorting first
// swap every two elements
// note i += 2 instead of usually i++
//
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0 ; i < nums.size(); i += 2) {
            swap(nums[i], nums[i+1]);
        }    
        return nums;
    }
};

