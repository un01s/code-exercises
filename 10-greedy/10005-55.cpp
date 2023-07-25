/*
 * leetcode 55
 *
 *
 *
 * 
 * Solution:
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// greedy: collect all positive profit every day as many as possible
// time O(n), space O(1)
// 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1) return true;

        for (int i = 0; i <= cover; i++) {
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
