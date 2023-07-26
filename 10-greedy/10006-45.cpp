/*
 * leetcode 45
 *
 *
 *
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        if (nums.size() == 1) return res;

        int curDist = 0;
        int nextDist = 0;
        for (int i = 0; i < nums.size(); i++) {
            nextDist = max(nums[i]+i, nextDist);
            if (i == curDist) {
                res++;
                curDist = nextDist;
                if (nextDist >= nums.size()-1) break;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
