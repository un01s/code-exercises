/*
 * leetcode 88
 * merge sorted array
 * 
 */

class Solution {
public:
    void merge(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int p1 = m-1, p2 = n-1;
        
        for (int i = m+n-1; i >= 0; i--) {
            if (p1 < 0) {
                nums1[i] = nums2[p2];
                p2--;
            } else if (p2 < 0) {
                nums1[i] = nums1[p1];
                p1--;
            } else if (nums[p1] > nums2[p2]) {
                nums1[i] = nums1[p1];
                p1--;
            } else {
                nums1[i] = nums2[p2];
                p2--;
            }
        }
    }
};

