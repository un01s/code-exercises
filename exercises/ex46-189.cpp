/*
 * rotate array
 * right shift k 
 *
 */

// overtime
class Solution {
public:
    void rightShift(vector<int>& nums) {
        int k = 0;
        int n = nums.size();
        int last = nums[n-1];
        for (int i = n-2; i >=0; i--) {
            nums[i+1] = nums[i];
        }
        nums[0] = last;
    }
    void rotate(vector<int>& nums, int k) {
        for(int i = 0; i < k; i++) {
            rightShift(nums);
        }
    }
};

// can we do it once?
// use space to exchange for time
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n, 0);
        
        for (int i = 0; i < n; i++) {
            res[(i+k)%n] = nums[i];
        }
        for (int i = 0; i < n; i++) {
            nums[i] = res[i];
        }
    }
};
