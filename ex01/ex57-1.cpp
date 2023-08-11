/*
 * leetcode 1 two sum
 *
 * 2023-07-25
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        
        for(int i = 0; i < nums.size(); i++){
        // not found the second one
            if (m.find(nums[i]) == m.end() ) {
            // store the first one poisition into the second one's key
                m[target - nums[i]] = i;
            } else {
            // found the second one
                res.push_back(m[nums[i]]);
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
