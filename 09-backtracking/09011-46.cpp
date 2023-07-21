/**
 * Leetcode 46 
 *
 * input: [1, 2, 3]
 * output: 
 * [[1, 2, 3], [1, 3, 2], [2, 3, 1], [2, 1, 3], [3, 1, 2], [3, 2, 1]]
 *
 * permutation, order matters here
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
    void backtracking(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path); // reach the leaf node, all nodes are used!
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(used[i] == true) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int> > permute(vector<int>& nums) {
        res.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }
};

int main() {
    
    return 0;
}

