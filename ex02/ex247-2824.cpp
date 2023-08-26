/*
 * leetcode 2824
 *
 * double-pointer
 *
 * https://www.youtube.com/@codeyao9796
 * 
 */

// wrong: repeated
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(nums[i]+nums[j] < target) cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;
        int r = n-1;
        sort(nums.begin(), nums.end()); // must 
        for(int i = 0; i < n-1; i++) {
            while(r > i && (nums[r]+nums[i] >= target)) {
                r--;
            }
            if(r <= i) break;
            cnt = cnt + r - i;
        }
        return cnt;
    }
};

