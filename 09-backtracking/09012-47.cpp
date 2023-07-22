/**
 * Leetcode 47 
 *
 * 
 *
 * 2023-07-22
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int> > res;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            // found one
            res.push_back(path);
            return;
        }
        // start to search one level
        for (int i = 0; i < nums.size(); i++) {
            // used[i-1] == true, nums[i-1] is used on the same branch
            // used[i-1] == false, nums[i-1] at the same level used
            // if at the same level nums[i-1] is used, simply pass
            if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false) {
                continue;
            }
            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        res.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
};

int main() {
    
    return 0;
}

