/*
 * leetcode 2422
 *
 * double-pointer
 * 
 */

using LL = long long;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        LL left = nums[i], right = nums[j];        
        int res = 0;
        
        while (i<j){
            if (left==right){
                i++;
                j--;
                left = nums[i];
                right = nums[j];                
            } else if (left < right){
                i++;
                left += nums[i];
                res++;
            }else if (left > right){
                j--;
                right += nums[j];
                res++;
            }
        }
        return res;
    }
};
