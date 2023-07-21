/**
 * Leetcode 90 
 *
 *
 * 2023-07-21
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > res;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex, vector<bool>& used) {
        res.push_back(path);
        for(int i = startIndex; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i+1, used);
            used[i] = false;
            path.pop_back();
        }
    }    
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        res.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end()); // sorting is important
        backtracking(nums, 0, used);
        return res;
    }
};

int main() {
    
    return 0;
}

