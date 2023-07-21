/**
 * Leetcode 491 
 *
 *
 * 2023-07-21
 *
 * subset with no duplicates, incremental,
 * at least two element, all equal set is incremental
 *
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int> > res;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        if (path.size() > 1) {
            res.push_back(path);
            // no return here
            // because all the nodes are collected
        }
        unordered_set<int> uset; // use it to remove duplicates at this level
        for(int i = startIndex; i < nums.size(); i++) {
            if((!path.empty() && nums[i] < path.back())
                || uset.find(nums[i]) != uset.end()) {
                continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }    
    vector<vector<int> > findSubsequences(vector<int>& nums) {
        res.clear();
        path.clear();
        backtracking(nums, 0);
        return res;
    }
};

int main() {
    
    return 0;
}

