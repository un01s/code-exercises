/*
 * leetcode 1537
 *
 * two arrays: distinct integers, increasing value
 * if one same value appears in both array, switch path is allowed
 * but only one unique value is counted into the path score
 * traverse current array from left to right
 * 
 * return the max score of all possible valid paths.
 * if the score is too large, module M = 1e9+7
 *
 * double-pointer
 *
 * how about DP?
 * check if any common integers in both array?
 * if no, max sum of one array
 * if yes, consider switch to max the score
 *
 *
 */

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long m = nums1.size();
        long n = nums2.size();
  
        long long x = 0, y = 0;
        long long i = 0, j = 0;
  
        long long M = 1e9+7;
        
        while (i<m || j<n){
            if (i==m){
                y+=nums2[j];
                j++;
            } else if (j==n){
                x+=nums1[i];
                i++;
            } else if (nums1[i]<nums2[j]){
                x += nums1[i];
                i++;
            } else if (nums1[i]>nums2[j]){
                y += nums2[j];
                j++;
            } else if (nums1[i]==nums2[j]){
                x = max(x, y)+nums1[i];
                y = x;
                i++;
                j++;
            }
        }
        return max(x,y)%M;    
    }
};

