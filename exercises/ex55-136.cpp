/*
 * leetcode 136
 *
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int r;
        unordered_map<int, int> m;
        
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        for(int i = 0; i < nums.size(); i++) {
            if (m[nums[i]] == 1) {
                r = nums[i];
                break;
            }
        }
        return r;
    }
};

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                return nums[i-1];
            }
            i++; // increment by 2
        }
        return nums[nums.size()-1];
    }
};


int main() {
    return 0;
}
